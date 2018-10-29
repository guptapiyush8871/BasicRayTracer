#include "RenderManager.h"
#include "Ray.h"
#include "Vertex3f.h"
#include "Vector3D.h"
#include <vector>
#include <utility>

RenderManager& RenderManager::GetRenderManager() 
{
	static RenderManager instance;
	return instance;
}

RenderManager::RenderManager() 
{
	Reset();
}

RenderManager::~RenderManager() 
{
	Reset();
}

void RenderManager::AttachScene(Scene* iScene) 
{
	m_Scene = iScene;
}

void RenderManager::AttachCamera(Camera* iCamera)
{
	m_Camera = iCamera;
}

void RenderManager::SetRenderConfig(const RenderConfig& iRenderConfig) 
{
	m_RenderConfig = iRenderConfig;
}

RenderConfig RenderManager::GetRenderConfig() const 
{
	return m_RenderConfig;
}

void RenderManager::RenderScene() const
{
	if (!m_Camera || !m_Scene)
		return;

	if (!m_Render)	//Lazy render creation
	{
		m_Render = new Render();
	}
	m_Render->SetRenderConfig(m_RenderConfig);

	RenderConfig::EMSAA msaa = m_RenderConfig.m_Msaa;
	unsigned int numSamples = (1 << msaa);
	unsigned int width = 0;
	unsigned int height = 0;
	m_Camera->GetResolution(width, height);
	size_t pixelDataSize = 0;
	char* pixelData = nullptr;
	int pixelDataStreamer = 0;
	m_Camera->GetRenderPlane()->CopyPixelData(&pixelData, pixelDataSize);

	int topLeftX = -(static_cast<int>(width / 2));
	int topLeftY = -(static_cast<int>(height / 2));
	int bottomRightX = (static_cast<int>(width / 2));
	int bottomRightY = (static_cast<int>(height / 2));

	std::vector<std::pair<float, float> > sampleLocations;
	size_t vecSize = sampleLocations.size();

	unsigned short finalRed = 0;
	unsigned short finalGreen = 0;
	unsigned short finalBlue = 0;
	unsigned short finalAlpha = 0;

	for (int row = topLeftY; row < bottomRightY; row++) 
	{
		for (int col = topLeftX; col < bottomRightX; col++) 
		{
			unsigned int red = 0;
			unsigned int green = 0;
			unsigned int blue = 0;
			unsigned int alpha = 0;

			for (unsigned int sampleLoc = 0; sampleLoc < vecSize; sampleLoc++)
			{
				unsigned short sampleRed = 0;
				unsigned short sampleGreen = 0;
				unsigned short sampleBlue = 0;
				unsigned short sampleAlpha = 0;

				float xOffset = sampleLocations[sampleLoc].first;
				float yOffset = sampleLocations[sampleLoc].second;
				Ray ray(Vertex3f(((float)col) + xOffset, ((float)row) + yOffset, 0.0f), Vector3D(0.0f, 0.0f, 1.0f));
				Sample finalSample = m_Render->Rendering(ray, m_Scene);
				if (finalSample.IsValid()) 
				{
					RGBAColor finalColor = finalSample.GetColor();
					finalColor.GetColor(sampleRed, sampleGreen, sampleBlue, sampleAlpha);
				}
				else 
				{
					m_RenderConfig.m_BackgroundColor.GetColor(sampleRed, sampleGreen, sampleBlue, sampleAlpha);
				}

				red += sampleRed;
				green += sampleGreen;
				blue += sampleBlue;
				alpha += sampleAlpha;
			}
			red = red / numSamples;
			green = green / numSamples;
			blue = blue / numSamples;
			alpha = alpha / numSamples;

			finalRed = static_cast<unsigned short> (red);
			finalGreen = static_cast<unsigned short> (green);
			finalBlue = static_cast<unsigned short> (blue);
			finalAlpha = static_cast<unsigned short> (alpha);

			std::memcpy(pixelData + pixelDataStreamer, &finalRed, sizeof(unsigned short));
			pixelDataStreamer += sizeof(unsigned short);
			std::memcpy(pixelData + pixelDataStreamer, &finalGreen, sizeof(unsigned short));
			pixelDataStreamer += sizeof(unsigned short);
			std::memcpy(pixelData + pixelDataStreamer, &finalBlue, sizeof(unsigned short));
			pixelDataStreamer += sizeof(unsigned short);
			std::memcpy(pixelData + pixelDataStreamer, &finalAlpha, sizeof(unsigned short));
			pixelDataStreamer += sizeof(unsigned short);
		}
	}

	m_Camera->GetRenderPlane()->SetPixelData(pixelData);
}

void RenderManager::Reset() 
{
	m_Scene = nullptr;
	m_Render = nullptr;
	m_Camera = nullptr;
	m_RenderConfig = RenderConfig();
	if (m_Render)
		delete m_Render;
	m_Render = nullptr;
}

#include "Render.h"
#include <vector>

Render::Render() 
{
}

Render::Render(const RenderConfig& iRenderConfig) 
{
	m_RenderConfig = iRenderConfig;
}

Render::Render(const Render& iRender) 
{
	m_RenderConfig = iRender.m_RenderConfig;
}

Render::~Render() 
{
}

void Render::SetRenderConfig(const RenderConfig& iRenderConfig) 
{
	m_RenderConfig = iRenderConfig;
}

RenderConfig Render::GetRenderConfig() const 
{
	return m_RenderConfig;
}

Sample Render::Rendering(Ray& iRay, Scene* iScene) const
{
	Sample sample;
	sample.MakeInvalid();
	std::vector<Shape*> shapes = iScene->GetAllShapes();
	float minDistance = std::numeric_limits<float>::infinity();
	for (unsigned int i = 0; i < shapes.size(); i++) 
	{
		Sample tempSample;
		shapes[i]->Hit(iRay, tempSample);
		if (tempSample.IsValid() && minDistance > tempSample.GetMinDistance())
		{
			minDistance = tempSample.GetMinDistance();
			sample = tempSample;
		}
	}

	return sample;
}

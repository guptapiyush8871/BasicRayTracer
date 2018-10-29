#include "RenderConfig.h"

RenderConfig::RenderConfig() :
	m_Msaa(e1X),
	m_BackgroundColor(RGBAColor())
{
}

std::vector<std::pair<float, float> > RenderConfig::GetSampleLocations(EMSAA iMsaa) const 
{
	std::vector<std::pair<float, float> > samplePositions;
	int row = 1;
	int col = 1;
	float startX = 0.5f;
	float startY = 0.5f;
	float spanX = 0.0f;
	float spanY = 0.0f;
	switch (iMsaa)
	{
	case e1X:
		break;

	case e2X:
		col = 2;
		startX = 0.25f;
		spanX = 0.5f;
		break;
	
	case e4X:
		row = 2;
		col = 2;
		startX = 0.25f;
		startY = 0.25f;
		spanX = 0.5f;
		spanY = 0.5f;
		break;
	
	case e8X:
		row = 2;
		col = 4;
		startX = 0.125f;
		startY = 0.25f;
		spanX = 0.25f;
		spanY = 0.5f;
		break;
	
	case e16X:
		row = 4;
		col = 4;
		startX = 0.125f;
		startY = 0.125f;
		spanX = 0.25f;
		spanY = 0.25f;
		break;
	
	default:
		break;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) 
		{
			samplePositions.push_back(std::pair<float, float>(startX + j*spanX, startY + i*spanY));
		}
	}

	return samplePositions;
}

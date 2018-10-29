#ifndef RENDER_SETTINGS_H
#define RENDER_SETTINGS_H

#include "RGBAColor.h"
#include <vector>
#include <utility>

class RenderConfig
{
public:
	enum EMSAA 
	{
		e1X = 0,
		e2X,
		e4X,
		e8X,
		e16X
	};

	EMSAA m_Msaa;
	RGBAColor m_BackgroundColor;

	RenderConfig();
	std::vector<std::pair<float, float> > GetSampleLocations(EMSAA iMsaa) const;
};

#endif

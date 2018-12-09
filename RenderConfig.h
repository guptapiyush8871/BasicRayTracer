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

	enum E_RENDER_PLANE_TYPE
	{
		eInt = sizeof(int),
		eUnsignedShort = sizeof(unsigned short),
		eChar = sizeof(char)
	};

	enum E_RENDER_PLANE_FORMAT 
	{
		eRGBA = 4
	};

	RenderConfig();
	~RenderConfig();

	void SetBackgroundColor(const RGBAColor& iBackgroundColor);
	RGBAColor GetBackgroundColor() const;
	
	void SetMSAA(const EMSAA iMsaa);
	EMSAA GetMSAA() const;
	std::vector<std::pair<float, float> > GetSampleLocations(EMSAA iMsaa) const;

	//Friends
	friend class RenderManager;

private:
	EMSAA m_Msaa;
	RGBAColor m_BackgroundColor;
};

#endif

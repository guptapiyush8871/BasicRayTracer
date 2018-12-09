#ifndef RENDER_PLANE_H
#define RENDER_PLANE_H

#include "Vertex3f.h"
#include "Vector3D.h"
#include "RenderConfig.h"

class RenderPlane 
{
public:
	RenderPlane();
	RenderPlane(const Vertex3f& iCenter, const Vector3D& iNormal, const unsigned int iWidth, const unsigned int iHeight, const RenderConfig::E_RENDER_PLANE_FORMAT iRenderPlaneFormat, const RenderConfig::E_RENDER_PLANE_TYPE iRenderPlaneType);
	RenderPlane(const RenderPlane& iRenderPlane);

	~RenderPlane();

	void SetCenter(const Vertex3f& iCenter);
	void SetNormal(const Vector3D& iNormal);

	size_t GetSize() const;
	RenderConfig::E_RENDER_PLANE_FORMAT GetRenderPlaneFormat() const;
	RenderConfig::E_RENDER_PLANE_TYPE GetRenderPlaneType() const;
			
	void CopyPixelData(char** oData, size_t& oSize) const;
	void SetPixelData(const char* iData);
	const RenderPlane& operator=(const RenderPlane& iRenderPlane);

private:
	Vertex3f m_Center;
	Vector3D m_Normal;
	unsigned int m_Width;
	unsigned int m_Height;
	RenderConfig::E_RENDER_PLANE_FORMAT m_RenderPlaneFormat;
	RenderConfig::E_RENDER_PLANE_TYPE m_RenderPlaneType;
	size_t m_Size;
	char *m_PixelData;
};

#endif

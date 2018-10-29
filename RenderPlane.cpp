#include "RenderPlane.h"
#include <cstdlib>
#include <cstring>

RenderPlane::RenderPlane() :
	m_Center(Vertex3f()),
	m_Normal(Vertex3f()),
	m_Width(512),
	m_Height(512)
{
	m_Size = m_Width*m_Height * 4;
	m_PixelData = (char*)malloc(m_Size);
	std::memset(m_PixelData, 0, m_Size);
}

RenderPlane::RenderPlane(const Vertex3f& iCenter, const Vector3D& iNormal, const unsigned int iWidth, const unsigned int iHeight) :
	m_Center(iCenter),
	m_Normal(iNormal),
	m_Width(iWidth),
	m_Height(iHeight)
{
	m_Size = m_Width*m_Height * 4;
	m_PixelData = (char*)malloc(m_Size);
	std::memset(m_PixelData, 0, m_Size);
}

RenderPlane::RenderPlane(const RenderPlane& iRenderPlane) 
{
	m_Center = iRenderPlane.m_Center;
	m_Normal = iRenderPlane.m_Normal;
	m_Width = iRenderPlane.m_Width;
	m_Height = iRenderPlane.m_Height;

	m_Size = iRenderPlane.m_Size;
	m_PixelData = (char*)malloc(m_Size);
	std::memcpy(m_PixelData, iRenderPlane.m_PixelData, m_Size);
}

RenderPlane::~RenderPlane() 
{
	if (!m_PixelData)
		free(m_PixelData);
	m_PixelData = nullptr;
}

void RenderPlane::SetCenter(const Vertex3f& iCenter)
{
	m_Center = iCenter;
}

void RenderPlane::SetNormal(const Vector3D& iNormal) 
{
	m_Normal = iNormal;
}

size_t RenderPlane::GetSize() const 
{
	return m_Size;
}

void RenderPlane::CopyPixelData(char** oData, size_t& oSize) const 
{
	oSize = m_Size;
	*oData = (char*)malloc(oSize);
	std::memcpy(oData, m_PixelData, oSize);
}

const RenderPlane& RenderPlane::operator=(const RenderPlane& iRenderPlane)
{
	m_Center = iRenderPlane.m_Center;
	m_Normal = iRenderPlane.m_Normal;
	m_Width = iRenderPlane.m_Width;
	m_Height = iRenderPlane.m_Height;

	m_Size = iRenderPlane.m_Size;
	m_PixelData = (char*)malloc(m_Size);
	std::memcpy(m_PixelData, iRenderPlane.m_PixelData, m_Size);
	return (*this);
}

void RenderPlane::SetPixelData(const char* iData)
{
	std::memcpy(m_PixelData, iData, m_Size);
}

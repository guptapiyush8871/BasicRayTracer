#include "Camera.h"

Camera::Camera() :
	m_Origin(Vertex3f()),
	m_Direction(Vector3D()),
	m_Width(512),
	m_Height(512),
	m_RenderPlaneMinDIstance(0.0f)
{
	m_RenderPlane = new RenderPlane(m_Origin, m_Direction, m_Width, m_Height, RenderConfig::E_RENDER_PLANE_FORMAT::eRGBA, RenderConfig::E_RENDER_PLANE_TYPE::eInt);
}

Camera::Camera(const Vertex3f& iOrigin, const Vector3D& iDirection, const unsigned int iWidth, const unsigned int iHeight, RenderConfig::E_RENDER_PLANE_FORMAT iRenderPlaneFormat, const RenderConfig::E_RENDER_PLANE_TYPE iRenderPlaneType) :
	m_Origin(iOrigin),
	m_Direction(iDirection),
	m_Width(iWidth),
	m_Height(iHeight),
	m_RenderPlaneMinDIstance(0.0f)
{
	m_RenderPlane = new RenderPlane(m_Origin, m_Direction, m_Width, m_Height, iRenderPlaneFormat, iRenderPlaneType);
}

Camera::Camera(const Camera& iCamera) 
{
	m_Origin = iCamera.m_Origin;
	m_Direction = iCamera.m_Direction;
	m_Width = iCamera.m_Width;
	m_Height = iCamera.m_Height;
	m_RenderPlaneMinDIstance = m_RenderPlaneMinDIstance;
	RenderConfig::E_RENDER_PLANE_FORMAT renderPlaneFormat = iCamera.GetRenderPlane()->GetRenderPlaneFormat();
	RenderConfig::E_RENDER_PLANE_TYPE renderPlaneType = iCamera.GetRenderPlane()->GetRenderPlaneType();
	m_RenderPlane = new RenderPlane(m_Origin, m_Direction, m_Width, m_Height, renderPlaneFormat, renderPlaneType);
}

Camera::~Camera() 
{
	if (m_RenderPlane)
		delete m_RenderPlane;
	m_RenderPlane = nullptr;
}

Vertex3f Camera::GetOrigin() const 
{
	return m_Origin;
}

Vector3D Camera::GetDirection() const 
{
	return m_Direction;
}

void Camera::GetResolution(unsigned int& oWidth, unsigned int& oHeight) const
{
	oWidth = m_Width;
	oHeight = m_Height;
}

void Camera::SetRenderPlaneDistance(const float iDistance)
{
	m_RenderPlaneMinDIstance = iDistance;
	Vertex3f center(m_Origin + m_Direction*iDistance);
	m_RenderPlane->SetCenter(center);

	Vector3D normal = m_Origin + m_Direction;
	normal.Normalize();
	m_RenderPlane->SetNormal(normal);
}

const float Camera::GetRenderPlanneDistance() const 
{
	return m_RenderPlaneMinDIstance;
}

RenderPlane* Camera::GetRenderPlane() const
{
	return m_RenderPlane;
}

size_t Camera::GetRenderPlaneSize() const
{
	return m_RenderPlane->GetSize();
}

const Camera& Camera::operator=(const Camera& iCamera) 
{
	m_Origin = iCamera.m_Origin;
	m_Direction = iCamera.m_Direction;
	m_Width = iCamera.m_Width;
	m_Height = iCamera.m_Height;
	m_RenderPlaneMinDIstance = m_RenderPlaneMinDIstance;
	RenderConfig::E_RENDER_PLANE_FORMAT renderPlaneFormat = iCamera.GetRenderPlane()->GetRenderPlaneFormat();
	RenderConfig::E_RENDER_PLANE_TYPE renderPlaneType = iCamera.GetRenderPlane()->GetRenderPlaneType();
	m_RenderPlane = new RenderPlane(m_Origin, m_Direction, m_Width, m_Height, renderPlaneFormat, renderPlaneType);
	return (*this);
}

#include "Ray.h"

Ray::Ray()
	:m_Origin(Vertex3f()), m_Direction(Vector3D(0.0f, 0.0f, 1.0f))
{
	m_Precision = 0.0001f;
}

Ray::Ray(const Vertex3f& iOrigin, const Vector3D& iDirection)
	:m_Origin(iOrigin), m_Direction(iDirection)
{
	m_Precision = 0.0001f;
}

Ray::Ray(const Ray& iRay) 
{
	m_Origin = iRay.m_Origin;
	m_Direction = iRay.m_Direction;
	m_Precision = iRay.m_Precision;
}

Ray::~Ray() 
{
}

Vertex3f Ray::GetOrigin() const 
{
	return m_Origin;
}

Vector3D Ray::GetDirection() const
{
	return m_Direction;
}

void Ray::GetRay(Vertex3f& oOrigin, Vector3D& oDirection) const
{
	oOrigin = m_Origin;
	oDirection = m_Direction;
}

void Ray::SetPrecision(const float iPrecision) 
{
	m_Precision = iPrecision;
}

float Ray::GetPrecision() const 
{
	return m_Precision;
}

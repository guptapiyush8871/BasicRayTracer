#include "Vertex3f.h"
#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D() 
{
	m_X = m_Y = 0.0f;
	m_Z = 1.0f;
}

Vector3D::Vector3D(const float iX, const float iY, const float iZ) 
{
	m_X = iX;
	m_Y = iY;
	m_Z = iZ;
}

Vector3D::Vector3D(const Vertex3f& iVertex) 
{
	iVertex.GetVertex(m_X, m_Y, m_Z);
}

Vector3D::Vector3D(const Vector3D& iVec) 
{
	m_X = iVec.m_X;
	m_Y = iVec.m_Y;
	m_Z = iVec.m_Z;
}

Vector3D::~Vector3D() 
{
}

Vector3D Vector3D::operator+(const float iVal) const 
{
	return Vector3D(m_X + iVal, m_Y + iVal, m_Z + iVal);
}

Vector3D Vector3D::operator-(const float iVal) const 
{
	return Vector3D(m_X - iVal, m_Y - iVal, m_Z - iVal);
}

Vector3D Vector3D::operator*(const float iVal) const 
{
	return Vector3D(m_X * iVal, m_Y * iVal, m_Z * iVal);
}

Vector3D Vector3D::operator/(const float iVal) const 
{
	if (0.0f == iVal)
		return Vector3D(0.0f, 0.0f, 0.0f);

	return Vector3D(m_X / iVal, m_Y / iVal, m_Z / iVal);
}

Vector3D Vector3D::operator+(const Vector3D& iVec) const
{
	return Vector3D(m_X + iVec.m_X, m_Y + iVec.m_Y, m_Z + iVec.m_Z);
}

Vector3D Vector3D::operator-(const Vector3D& iVec) const
{
	return Vector3D(m_X - iVec.m_X, m_Y - iVec.m_Y, m_Z - iVec.m_Z);
}

float Vector3D::operator*(const Vector3D& iVec) const
{
	return (m_X * iVec.m_X + m_Y * iVec.m_Y + m_Z * iVec.m_Z);
}

void Vector3D::Normalize() 
{
	float dist = std::sqrt(m_X*m_X + m_Y*m_Y + m_Z*m_Z);
	if (dist != 0.0f) 
	{
		m_X = m_X / dist;
		m_Y = m_Y / dist;
		m_Z = m_Z / dist;
	}
}

Vector3D Vector3D::GetUnitVector() const
{
	float dist = std::sqrt(m_X*m_X + m_Y*m_Y + m_Z*m_Z);
	if (0.0f == dist)
		return Vector3D(0.0f, 0.0f, 0.0f);

	return Vector3D(m_X / dist, m_Y / dist, m_Z / dist);
}

void Vector3D::GetData(float& oX, float& oY, float& oZ) const 
{
	oX = m_X;
	oY = m_Y;
	oZ = m_Z;
}

void Vector3D::GetNormalizeData(float& oX, float& oY, float& oZ) const
{
	float dist = std::sqrt(m_X*m_X + m_Y*m_Y + m_Z*m_Z);
	if (dist != 0.0f)
	{
		oX = m_X / dist;
		oY = m_Y / dist;
		oZ = m_Z / dist;
	}
}

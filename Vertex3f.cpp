#include "Vector3D.h"
#include "Vertex3f.h"

Vertex3f::Vertex3f() 
{
	m_X = 0.0f;
	m_Y = 0.0f;
	m_Z = 0.0f;
}

Vertex3f::Vertex3f(const float iX, const float iY, const float iZ) 
{
	m_X = iX;
	m_Y = iY;
	m_Z = iZ;
}

Vertex3f::Vertex3f(const Vector3D& iVector)
{
	iVector.GetData(m_X, m_Y, m_Z);
}

Vertex3f::Vertex3f(const Vertex3f& iVertex) 
{
	m_X = iVertex.m_X;
	m_Y = iVertex.m_Y;
	m_Z = iVertex.m_Z;
}

Vertex3f::~Vertex3f() 
{
}

void Vertex3f::SetVertex(const float iX, const float iY, const float iZ) 
{
	m_X = iX;
	m_Y = iY;
	m_Z = iZ;
}

void Vertex3f::GetVertex(float& oX, float& oY, float& oZ) const 
{
	oX = m_X;
	oY = m_Y;
	oZ = m_Z;
}

Vertex3f Vertex3f::operator+(const float iVal) const
{
	return Vertex3f(m_X + iVal, m_Y + iVal, m_Z + iVal);
}

Vertex3f Vertex3f::operator-(const float iVal) const
{
	return Vertex3f(m_X - iVal, m_Y - iVal, m_Z - iVal);
}

Vertex3f Vertex3f::operator*(const float iVal) const
{
	return Vertex3f(m_X * iVal, m_Y * iVal, m_Z * iVal);
}

Vertex3f Vertex3f::operator/(const float iVal) const
{
	return Vertex3f(m_X / iVal, m_Y / iVal, m_Z / iVal);
}

Vertex3f Vertex3f::operator+(const Vertex3f& iVec) const
{
	return Vertex3f(m_X + iVec.m_X, m_Y + iVec.m_Y, m_Z + iVec.m_Z);
}

Vertex3f Vertex3f::operator-(const Vertex3f& iVec) const
{
	return Vertex3f(m_X - iVec.m_X, m_Y - iVec.m_Y, m_Z - iVec.m_Z);
}

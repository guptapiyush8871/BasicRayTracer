#include "Sample.h"
#include "Plane.h"

Plane::Plane() :
	m_Origin(Vertex3f()),
	m_Normal(Vector3D()),
	m_Color(RGBAColor())
{
}

Plane::Plane(const Vertex3f& iOrigin, const Vector3D iNormal, const RGBAColor& iColor) :
	m_Origin(iOrigin),
	m_Normal(iNormal),
	m_Color(iColor)
{
}

Plane::Plane(const Plane& iPlane)
{
	m_Origin = iPlane.m_Origin;
	m_Normal = iPlane.m_Normal;
	m_Color = iPlane.m_Color;
}

Plane::~Plane()
{
}

void Plane::SetColor(const RGBAColor& iColor)
{
	m_Color = iColor;
}

RGBAColor Plane::GetColor() const
{
	return m_Color;
}

const Shape* Plane::GetShape() const
{
	return this;
}

void Plane::Hit(const Ray& iRay, Sample& oSample) const
{
	Vertex3f rayOrigin(iRay.GetOrigin());
	Vector3D rayDirection(iRay.GetDirection());
	Vector3D diff = Vector3D(m_Origin - rayOrigin);

	float denominator = rayDirection*m_Normal;
	if (denominator != 0)
	{
		float precision = iRay.GetPrecision();
		float minDistance = (diff*m_Normal) / denominator;
		if (minDistance > precision)
		{
			Vertex3f hitPoint(Vector3D(rayOrigin) + (rayDirection * minDistance));
			oSample.SetShape(this);
			oSample.SetColor(m_Color);
			oSample.SetVertex(hitPoint);
			oSample.SetMinDistance(minDistance);
			oSample.MakeValid();
			return;
		}
	}
	
	oSample.MakeInvalid();
}

Vertex3f Plane::GetOrigin() const
{
	return m_Origin;
}

Vector3D Plane::GetNormal() const
{
	return m_Normal;
}


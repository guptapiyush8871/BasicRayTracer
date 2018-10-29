#include "Sample.h"
#include "Sphere.h"
#include <cmath>

Sphere::Sphere()
	:m_Center(Vertex3f()), m_Color(RGBAColor()), m_Radius(1.0f)
{
}

Sphere::Sphere(const Vertex3f iCenter, const RGBAColor iColor, const float iRadius)
	: m_Center(iCenter), m_Color(iColor), m_Radius(iRadius)
{
}

Sphere::Sphere(const Sphere& iSphere)
{
	m_Center = iSphere.m_Center;
	m_Color = iSphere.m_Color;
	m_Radius = iSphere.m_Radius;
}

Sphere::~Sphere()
{
}

void Sphere::SetColor(const RGBAColor& iColor)
{
	m_Color = iColor;
}

RGBAColor Sphere::GetColor() const
{
	return m_Color;
}

const Shape* Sphere::GetShape() const
{
	return this;
}

void Sphere::Hit(const Ray& iRay, Sample& oSample) const
{
	Vector3D rayDirection(iRay.GetDirection());
	Vector3D rayOrigin(iRay.GetOrigin());
	Vector3D diffVector = rayOrigin - m_Center;
	float a = rayDirection * rayDirection;
	float b = 2 * (diffVector * rayDirection);
	float c = (diffVector * diffVector) - (m_Radius * m_Radius);
	float D = b * b - 4 * a * c;
	float precision = iRay.GetPrecision();
	float denominator = 2 * a;
	if (D < 0 || 0 == denominator)
	{
		oSample.MakeInvalid();
	}
	else
	{
		bool bHitFlag = false;
		float minDistance = 0.0f;
		float sqrtD = std::sqrt(D);
		minDistance = (-b - sqrtD) / denominator;
		if (minDistance > precision)
		{
			bHitFlag = true;
			return;
		}

		minDistance = (b - sqrtD) / denominator;
		if (minDistance > precision)
		{
			bHitFlag = true;
			return;
		}

		if (bHitFlag)
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

float Sphere::GetRadius() const
{
	return m_Radius;
}

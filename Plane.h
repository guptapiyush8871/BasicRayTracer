#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"
#include "Vertex3f.h"
#include "Vector3D.h"

class Plane : public Shape
{
public:
	Plane();
	Plane(const Vertex3f& iOrigin, const Vector3D iNormal, const RGBAColor& iColor);
	Plane(const Plane& iPlane);

	virtual ~Plane();

	virtual void SetColor(const RGBAColor& iColor);
	virtual RGBAColor GetColor() const;
	virtual const Shape* GetShape() const;
	virtual void Hit(const Ray& iRay, Sample& oSample) const;

	Vertex3f GetOrigin() const;
	Vector3D GetNormal() const;

private:
	Vertex3f m_Origin;
	Vector3D m_Normal;
	RGBAColor m_Color;
};

#endif

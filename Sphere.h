#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"
#include "Vertex3f.h"

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(const Vertex3f iCenter, const RGBAColor iColor, const float iRadius);
	Sphere(const Sphere& iSphere);

	virtual ~Sphere();
	
	virtual void SetColor(const RGBAColor& iColor);
	virtual RGBAColor GetColor() const;
	virtual const Shape* GetShape() const;
	virtual void Hit(const Ray& iRay, Sample& oSample) const;

	float GetRadius() const;

private:
	Vertex3f m_Center;
	RGBAColor m_Color;
	float m_Radius;
};

#endif

#ifndef SHAPE_H
#define SHAPE_H

#include "Ray.h"
#include "RGBAColor.h"

class Sample;

class Shape 
{
public:
	virtual ~Shape() {};

	virtual void SetColor(const RGBAColor& iColor) = 0;
	virtual RGBAColor GetColor() const = 0;
	virtual const Shape* GetShape() const = 0;
	virtual void Hit(const Ray& iRay, Sample& oSample) const = 0;
};

#endif

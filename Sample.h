#ifndef SAMPLE_H
#define SAMPLE_H

#include "RGBAColor.h"
#include "Vertex3f.h"

class Shape;

class Sample 
{
public:
	Sample();
	~Sample();

	void SetColor(const RGBAColor& iColor);
	RGBAColor GetColor() const;

	void SetVertex(const Vertex3f& iVertex);
	Vertex3f GetVertex() const;

	void SetShape(const Shape* iShape);
	const Shape* GetShape() const;

	void SetMinDistance(const float iDistance);
	float GetMinDistance() const;

	void GetSample(RGBAColor& oColor, Vertex3f& oVertex, const Shape* oShape) const;

	void MakeValid();
	void MakeInvalid();
	bool IsValid() const;

private:
	float m_MinDistance;
	RGBAColor m_Color;
	Vertex3f m_Vertex;
	const Shape* m_Shape;
	bool m_Valid;
};

#endif

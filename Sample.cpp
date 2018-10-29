#include "Shape.h"
#include "Sample.h"
#include <limits>

Sample::Sample()
	:m_Color(RGBAColor()), 
	m_Vertex(Vertex3f()), 
	m_Shape(nullptr), 
	m_Valid(false), 
	m_MinDistance(std::numeric_limits<float>::infinity())
{
}

Sample::~Sample() 
{
	m_Shape = nullptr;
}

void Sample::SetColor(const RGBAColor& iColor) 
{
	m_Color = iColor;
}

RGBAColor Sample::GetColor() const
{
	return m_Color;
}

void Sample::SetVertex(const Vertex3f& iVertex) 
{
	m_Vertex = iVertex;
}

Vertex3f Sample::GetVertex() const
{
	return m_Vertex;
}

void Sample::SetShape(const Shape* iShape) 
{
	m_Shape = iShape;
}

const Shape* Sample::GetShape() const 
{
	return m_Shape;
}

void Sample::SetMinDistance(const float iDistance) 
{
	m_MinDistance = iDistance;
}

float Sample::GetMinDistance() const 
{
	return m_MinDistance;
}

void Sample::GetSample(RGBAColor& oColor, Vertex3f& oVertex, const Shape* oShape) const
{
	oColor = m_Color;
	oVertex = m_Vertex;
	oShape = m_Shape;
}

void Sample::MakeValid() 
{
	m_Valid = true;
}

void Sample::MakeInvalid() 
{
	m_Valid = false;
}

bool Sample::IsValid() const 
{
	return m_Valid;
}

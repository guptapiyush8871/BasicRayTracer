#ifndef RAY_H
#define RAY_H

#include "Vertex3f.h"
#include "Vector3D.h"

class Ray 
{
public:
	Ray();
	Ray(const Vertex3f& iOrigin, const Vector3D& iDirection);
	Ray(const Ray& iRay);

	~Ray();

	Vertex3f GetOrigin() const;
	Vector3D GetDirection() const;
	void GetRay(Vertex3f& oOrigin, Vector3D& oDirection) const;
	void SetPrecision(const float iPrecision);
	float GetPrecision() const;

private:
	Vertex3f m_Origin;
	Vector3D m_Direction;
	float m_Precision;
};

#endif

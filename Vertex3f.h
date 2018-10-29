#ifndef VERTEX3F_H
#define VERTEX3F_H

class Vector3D;

class Vertex3f 
{
public:
	Vertex3f();
	Vertex3f(const float iX, const float iY, const float iZ);
	Vertex3f(const Vector3D& iVector);
	Vertex3f(const Vertex3f& iVertex);
	~Vertex3f();

	void SetVertex(const float iX, const float iY, const float iZ);
	void GetVertex(float& oX, float& oY, float& oZ) const;

	Vertex3f operator+(const float iVal) const;
	Vertex3f operator-(const float iVal) const;
	Vertex3f operator*(const float iVal) const;
	Vertex3f operator/(const float iVal) const;

	Vertex3f operator+(const Vertex3f& iVec) const;
	Vertex3f operator-(const Vertex3f& iVec) const;
	
private:
	float m_X;
	float m_Y;
	float m_Z;
};

#endif

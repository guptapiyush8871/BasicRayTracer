#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vertex3f;

class Vector3D 
{
public:
	Vector3D();
	Vector3D(const float iX, const float iY, const float iZ);
	Vector3D(const Vertex3f& iVertex);
	Vector3D(const Vector3D& iVec);
	~Vector3D();

	Vector3D operator+(const float iVal) const;
	Vector3D operator-(const float iVal) const;
	Vector3D operator*(const float iVal) const;
	Vector3D operator/(const float iVal) const;

	Vector3D operator+(const Vector3D& iVec) const;
	Vector3D operator-(const Vector3D& iVec) const;
	float operator*(const Vector3D& iVec) const;

	void Normalize();
	Vector3D GetUnitVector() const;

	void GetData(float& oX, float& oY, float& oZ) const;
	void GetNormalizeData(float& oX, float& oY, float& oZ) const;

private:
	float m_X;
	float m_Y;
	float m_Z;
};

#endif

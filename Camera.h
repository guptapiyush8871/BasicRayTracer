#ifndef CAMERA_H
#define CAMERA_H

#include "RenderPlane.h"
#include "Vertex3f.h"
#include "Vector3D.h"

class Camera 
{
public:
	Camera();
	Camera(const Vertex3f& iOrigin, const Vector3D& iDirection, const unsigned int iWidth, const unsigned int iHeight);
	Camera(const Camera& iCamera);
	~Camera();

	Vertex3f GetOrigin() const;
	Vector3D GetDirection() const;
	void GetResolution(unsigned int& oWidth, unsigned int& oHeight) const;

	void SetRenderPlaneDistance(const float iDistance);
	const float GetRenderPlanneDistance() const;
	RenderPlane* GetRenderPlane() const;
	size_t GetRenderPlaneSize() const;

	const Camera& operator=(const Camera& iCamera);
	
private:
	Vertex3f m_Origin;
	Vector3D m_Direction;
	unsigned int m_Width;
	unsigned int m_Height;
	float m_RenderPlaneMinDIstance;
	RenderPlane* m_RenderPlane;
};

#endif

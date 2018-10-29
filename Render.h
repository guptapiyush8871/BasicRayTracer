#ifndef RENDER_H
#define RENDER_H

#include "Ray.h"
#include "RenderConfig.h"
#include "Scene.h"
#include "Sample.h"

class Render 
{
public:
	Render();
	Render(const RenderConfig& iRenderConfig);
	Render(const Render& iRender);

	~Render();

	void SetRenderConfig(const RenderConfig& iRenderConfig);
	RenderConfig GetRenderConfig() const;
	Sample Rendering(Ray& iRay, Scene* iScene) const;

private:
	RenderConfig m_RenderConfig;
};

#endif

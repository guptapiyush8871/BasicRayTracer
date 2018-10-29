#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include "Scene.h"
#include "RenderConfig.h"
#include "Render.h"
#include "Camera.h"
#include "Sample.h"

//Singleton
class RenderManager 
{
public:
	static RenderManager& GetRenderManager();

	void AttachScene(Scene* iScene);
	void AttachCamera(Camera* iCamera);
	void SetRenderConfig(const RenderConfig& iRenderConfig);
	RenderConfig GetRenderConfig() const;
	void Reset();

	void RenderScene() const;	//Render for each ray

private:
	RenderManager();
	RenderManager(const RenderManager& iRenderManager);
	~RenderManager();

	const RenderManager& operator=(const RenderManager& iRenderManager);
		
	Scene* m_Scene;
	mutable Render* m_Render;
	Camera* m_Camera;
	RenderConfig m_RenderConfig;
};

#endif

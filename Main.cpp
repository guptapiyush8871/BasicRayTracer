#include "Vertex3f.h"
#include "Vector3D.h"
#include "RGBAColor.h"
#include "Camera.h"
#include "Sphere.h"
#include "Scene.h"
#include "RenderConfig.h"
#include "RenderManager.h"
#include "RenderPlane.h"
#include <GL/glew.h>

#define WIDTH 256
#define HEIGHT 256

int main(void) 
{
	//Create Camera
	Camera* camera = new Camera(Vertex3f(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 1.0f), WIDTH, HEIGHT);
	
	//Create Scene
	Sphere* sphere = new Sphere(Vertex3f(0.0f, 0.0f, 6.0f), RGBAColor(255, 0, 0, 255), 6.0f);
	Scene* scene = new Scene();
	scene->AddShape(sphere);

	//Configure RenderManager
	RenderConfig renderConfig;
	RenderManager& renderManager = RenderManager::GetRenderManager();
	renderManager.AttachCamera(camera);
	renderManager.AttachScene(scene);
	renderManager.SetRenderConfig(renderConfig);
	
	//RenderScene
	renderManager.RenderScene();

	//Get RenderPlane
	RenderPlane* renderPlane = camera->GetRenderPlane();
	
	//Dump Frame
	char* pixelData = nullptr;
	size_t dataSize = 0;
	renderPlane->CopyPixelData(&pixelData, dataSize);
	//////Dump image need to be implement
	
	//Destroy
	renderManager.Reset();
	delete scene;
	delete sphere;
	delete camera;

	if (!pixelData)
		free(pixelData);
	pixelData = nullptr;

	_CrtDumpMemoryLeaks();	//To check the memprt leakage

	return 0;
}

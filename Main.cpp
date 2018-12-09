#include "Vertex3f.h"
#include "Vector3D.h"
#include "RGBAColor.h"
#include "Camera.h"
#include "Sphere.h"
#include "Scene.h"
#include "RenderConfig.h"
#include "RenderManager.h"
#include "RenderPlane.h"
#include <Magick++.h>
#include <iostream>

using namespace Magick;

#define WIDTH 1024
#define HEIGHT 1024

int main(int argc, char ** argv)
{
	//Create Camera
	Camera* camera = new Camera(Vertex3f(0.0f, 0.0f, 0.0f), Vector3D(0.0f, 0.0f, 1.0f), WIDTH, HEIGHT, RenderConfig::E_RENDER_PLANE_FORMAT::eRGBA, RenderConfig::E_RENDER_PLANE_TYPE::eChar);
	
	//Create Scene
	Sphere* sphere = new Sphere(Vertex3f(0.0f, 0.0f, 6.0f), RGBAColor(255, 0, 0, 255), 50.0f);
	Scene* scene = new Scene();
	scene->AddShape(sphere);

	//Configure RenderManager
	RenderConfig renderConfig;
	renderConfig.SetBackgroundColor(RGBAColor(255, 255, 255, 255));
	//renderConfig.SetMSAA(RenderConfig::e4X);

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
	
	//Dump the rendered frame
	try 
	{
		InitializeMagick("");

		//Method1
		unsigned char* frameData = reinterpret_cast<unsigned char*> (pixelData);
		std::string map("RGBA");
		Image frame(WIDTH, HEIGHT, map, StorageType::CharPixel, frameData);
		frame.depth(8);

		//Method2
		//Blob frameData(pixelData, dataSize);
		//Image frame;
		//frame.size(Geometry(WIDTH, HEIGHT));
		//frame.depth(8);
		//frame.magick("PNG");
		//frame.read(frameData);

		//API Test
		//Image frame("Mountain.jpg");
		//frame.write("Mountain2.jpg");
		
		frame.write("F:\\Raytracing\\BasicRaytracer\\Output\\Frame.png");
	}
	catch (Exception& ERROR) 
	{
		std::cout << "Caught exception: " << ERROR.what() << std::endl;
		return 1;
	}
	
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

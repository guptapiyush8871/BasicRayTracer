#include "Scene.h"

Scene::Scene() 
{

}

Scene::~Scene() 
{
	ClearScene();
}

void Scene::AddShape(Shape* iShape) 
{
	m_Shapes.push_back(iShape);
}

bool Scene::RemoveShape(const unsigned int iIndex) 
{
	if (iIndex < m_Shapes.size())
	{
		m_Shapes.erase(m_Shapes.begin() + iIndex);
		return true;
	}

	return false;
}

void Scene::ClearScene() 
{
	if (!m_Shapes.empty()) 
	{
		m_Shapes.clear();
	}
}

Shape* Scene::GetShape(const unsigned int iIndex) const 
{
	if (iIndex < m_Shapes.size()) 
	{
		return m_Shapes[iIndex];
	}

	return nullptr;
}

std::vector <Shape*> Scene::GetAllShapes() const 
{
	return m_Shapes;
}

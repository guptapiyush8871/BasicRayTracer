#ifndef SCENE_H
#define SCENE_H

#include "Shape.h"
#include <vector>

class Scene 
{
public:
	Scene();
	~Scene();

	void AddShape(Shape* iShape);
	bool RemoveShape(const unsigned int iIndex);
	void ClearScene();

	Shape* GetShape(const unsigned int iIndex) const;
	std::vector <Shape*> GetAllShapes() const;

private:
	std::vector <Shape*> m_Shapes;
};

#endif

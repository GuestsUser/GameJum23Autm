#pragma once
#include "Scene.h"
#include <vector>

class SceneAccessor
{
private:
	SceneAccessor();
public:
	void Initialize();
	SceneAccessor* GetInstance();
	void Finalize();
	~SceneAccessor();

private:
	static SceneAccessor* instance;
	std::vector<Scene*> active_scenes;
};


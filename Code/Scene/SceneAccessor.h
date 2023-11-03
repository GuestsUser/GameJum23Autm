#pragma once
#include <vector>
#include "Scene.h"
class Scene;

class SceneAccessor
{
private:
	SceneAccessor(Scene* _active_scene);
public:
	static void Initialize(Scene* _active_scene);	//©•ª‚Ì¶¬
	static SceneAccessor* GetInstance();	//©•ª‚Ìinstance‚ğŠO•”‚ÉŒöŠJ
	void Finalize();						//©•ª‚Ìíœ
	~SceneAccessor();

	void SetCurrentScene(Scene* _active_scene);

	Scene* GetCurrentScene()
	{
		return GetCurrentScene();
	}

private:
	static SceneAccessor* instance;
	Scene* active_scene;
};


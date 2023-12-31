#pragma once
#include <vector>
#include "Scene.h"
class Scene;

class SceneAccessor
{
private:
	SceneAccessor(Scene* _active_scene);
public:
	static void Initialize(Scene* _active_scene);	//自分の生成
	static SceneAccessor* GetInstance();	//自分のinstanceを外部に公開
	void Finalize();						//自分の削除
	~SceneAccessor();

	void SetCurrentScene(Scene* _active_scene);

	Scene* GetCurrentScene()
	{
		return active_scene;
	}

private:
	static SceneAccessor* instance;
	Scene* active_scene;
};


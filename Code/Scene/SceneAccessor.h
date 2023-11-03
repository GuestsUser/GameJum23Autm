#pragma once
#include <vector>
#include "Scene.h"
class Scene;

class SceneAccessor
{
private:
	SceneAccessor(Scene* _active_scene);
public:
	static void Initialize(Scene* _active_scene);	//�����̐���
	static SceneAccessor* GetInstance();	//������instance���O���Ɍ��J
	void Finalize();						//�����̍폜
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


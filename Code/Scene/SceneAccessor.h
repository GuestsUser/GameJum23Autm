#pragma once
#include "Scene.h"
#include <vector>

class SceneAccessor
{
private:
	SceneAccessor(Scene* _active_scene);
public:
	void Initialize(Scene* _active_scene);	//�����̐���
	static SceneAccessor* GetInstance();	//������instance���O���Ɍ��J
	void Finalize();						//�����̍폜
	~SceneAccessor();

	Scene* GetCurrentScene()
	{
		return GetCurrentScene();
	}

private:
	static SceneAccessor* instance;
	Scene* active_scene;
};


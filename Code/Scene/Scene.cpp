#include "Scene/Scene.h"

Scene::~Scene()
{
	DestroyAllObjects();
}

void Scene::Update()
{
	for (int i = 0; i < scene_objects.size(); i++) 
	{
		scene_objects[i]->Update();
	}
}

void Scene::Draw()
{
	for (int i = 0; i < scene_objects.size(); i++)
	{
		scene_objects[i]->Draw();
	}
}

void Scene::DestroyObject(Charactor* object)
{
	if (object == nullptr)
	{
		return;
	}

	//	削除対象の検索
	auto iterator = scene_objects.begin();
	for (; iterator != scene_objects.end(); ++iterator)
	{
		if ((*iterator) == object)
		{
			break;
		}
	}

	//	見つからなかった場合は終了
	if (iterator == scene_objects.end())
	{
		return;
	}

	//	削除
	scene_objects.erase(iterator);
	delete object;
}

void Scene::DestroyAllObjects()
{
	for (auto iterator = scene_objects.begin(); iterator != scene_objects.end(); ++iterator)
	{
		delete (*iterator);
	}
	scene_objects.clear();
}
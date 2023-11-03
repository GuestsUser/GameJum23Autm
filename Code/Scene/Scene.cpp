#include "Scene/Scene.h"
#include "QuickSort.h"
#include "SceneAccessor.h"

Scene::~Scene()
{
	DestroyAllObjects();
}

void Scene::Update()
{
	for (auto iterator = scene_objects.begin(); iterator != scene_objects.end(); iterator++)
	{
		(*iterator)->Update();
	}
}

void Scene::Draw()
{
	for (auto iterator = scene_objects.begin(); iterator != scene_objects.end(); iterator++)
	{
		(*iterator)->Draw();
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

void Scene::SortBasedOnPriority()
{
	QuickSort(scene_objects, 0, (scene_objects.size() - 1));
}
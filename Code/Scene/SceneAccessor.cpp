#include "SceneAccessor.h"
SceneAccessor* SceneAccessor::instance = nullptr;

SceneAccessor::SceneAccessor(Scene* _active_scene)
	:active_scene(_active_scene)
{

}

SceneAccessor::~SceneAccessor()
{

}

void SceneAccessor::Initialize(Scene* _active_scene)
{
	if (instance == nullptr)
	{
		instance = new SceneAccessor(_active_scene);
	}
}

SceneAccessor* SceneAccessor::GetInstance()
{
	if (instance == nullptr)
	{
		throw "SceneAccessor‚Ìinstance‚ª‚ ‚è‚Ü‚¹‚ñ";
	}
	return instance;
}

void SceneAccessor::Finalize()
{
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}
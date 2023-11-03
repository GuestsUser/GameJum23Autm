#include "SceneAccessor.h"
SceneAccessor* SceneAccessor::instance = nullptr;

SceneAccessor::SceneAccessor()
{

}

SceneAccessor::~SceneAccessor()
{

}

void SceneAccessor::Initialize()
{
	if (instance == nullptr)
	{
		instance = new SceneAccessor();
	}
}

SceneAccessor* SceneAccessor::GetInstance()
{

	return instance;
}
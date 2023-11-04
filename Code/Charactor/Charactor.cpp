#include "Charactor.h"
#include "SceneAccessor.h"

void Charactor::SetDrawPriority(int in_draw_priority)
{
	draw_priority = in_draw_priority;
	SceneAccessor::GetInstance()->GetCurrentScene()->SortBasedOnPriority();
}
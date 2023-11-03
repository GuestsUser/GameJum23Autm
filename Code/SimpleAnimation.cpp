#include "DxLib.h"
#include "SimpleAnimation.h"

SimpleAnimation::SimpleAnimation(int in_image, Vector3 in_pos, Vector3 in_target_pos, int moving_frame)
	:image(in_image)
	,position(in_pos)
	,target_position(in_target_pos)
	,is_moving(true)
{
	speed.SetXYZ((target_position - position)/moving_frame);
}

SimpleAnimation::~SimpleAnimation()
{

}

void SimpleAnimation::Update()
{
	position += speed;
	//	0.01ÇÕfloatåÎç∑Ç÷ÇÃëŒèà
	if (position.GetX() - abs(speed.GetX()) - 0.01 < target_position.GetX() &&
		position.GetX() + abs(speed.GetX()) + 0.01 > target_position.GetX() &&
		position.GetY() - abs(speed.GetY()) - 0.01 < target_position.GetY() &&
		position.GetY() + abs(speed.GetY()) + 0.01 > target_position.GetY()
		)
	{
		is_moving = false;
		speed = Vector3(0, 0, 0);
	}
}

void SimpleAnimation::Draw()
{
	DrawRotaGraphF(position.GetX(), position.GetY(), 1, 0, image, TRUE);
}
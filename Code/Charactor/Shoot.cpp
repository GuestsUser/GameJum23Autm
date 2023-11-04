#include "Shoot.h"

Shoot::Shoot()//�R���X�g���N�^
{
	box_x_half = 16.f;			//Box�̉����W�̔��a
	box_y_half = 24.f;			//Box�̏c���W�̔��a

	shoot_max_speed = 4.f;		//Box�̈ړ����x

	box_flg = true;
}
Shoot::~Shoot()//�f�X�g���N�^
{

}
void Shoot::Update()
{
	EditPosition().GetX();

	EditPosition().SetX(EditPosition().GetX() + shoot_speed);
	if (((shoot_speed < 0) && (EditPosition().GetX() <= (960.f / 2.f)))
		|| ((shoot_speed > 0) && (EditPosition().GetX() >= (960.f / 2.f))))
	{
		box_flg = false;
	}
}
void Shoot::Draw()
{
	float box_left_x = (EditPosition().GetX() - box_x_half);
	float box_left_y = (EditPosition().GetY() - box_y_half);
	float box_right_x = (EditPosition().GetX() + box_x_half);
	float box_right_y = (EditPosition().GetY() + box_y_half);

	if ((box_flg == TRUE) && (color == Color::BLUE))
	{	
		//�V�A���̃{�b�N�X��`��
		DrawBox(box_left_x, box_left_y, box_right_x, box_right_y, 0x00ffff, TRUE);
		DrawGraph(box_left_x,box_left_y,)
	}
	if ((box_flg == TRUE) && (color == Color::RED))
	{
		//�}�[���^�̃{�b�N�X�̕`��
		DrawBox(box_left_x, box_left_y, box_right_x, box_right_y, 0xff00ff, TRUE);
	}
}
void Shoot::SetSpeed(float speed)
{
	shoot_speed = speed;
	if (shoot_max_speed <= speed)
	{
		shoot_speed = shoot_max_speed;
	}
}
void Shoot::SetBoxColor(Color color_)
{
	color = color_;
}

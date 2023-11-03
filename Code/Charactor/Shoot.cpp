#include "Shoot.h"

Shoot::Shoot()//�R���X�g���N�^
{
	EditPosition().SetX(1100);	//Box�̒��S���W��X�l
	EditPosition().SetY(400);	//Box�̒��S���W��Y�l

	box_x_half = 16.f;			//Box�̉����W�̔��a
	box_y_half = 24.f;			//Box�̏c���W�̔��a

	shoot_speed = 3.f;			//Box�̈ړ����x

	box_flg = true;
}
Shoot::~Shoot()//�f�X�g���N�^
{

}
void Shoot::Update()
{
	EditPosition().GetX();

	EditPosition().SetX(EditPosition().GetX() - shoot_speed);
	if (EditPosition().GetX() <= 480)
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

	if (box_flg == true)
	{	
		//Box���쐬
		DrawBox(box_left_x, box_left_y, box_right_x, box_right_y, 0x00ffff, TRUE);
	}
}
#include "Shoot.h"

Shoot::Shoot()//コンストラクタ
{
	box_x_half = 16.f;			//Boxの横座標の半径
	box_y_half = 24.f;			//Boxの縦座標の半径

	shoot_max_speed = 4.f;		//Boxの移動速度

	box_flg = true;
}
Shoot::~Shoot()//デストラクタ
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
		//シアンのボックスを描画
		DrawBox(box_left_x, box_left_y, box_right_x, box_right_y, 0x00ffff, TRUE);
		DrawGraph(box_left_x,box_left_y,)
	}
	if ((box_flg == TRUE) && (color == Color::RED))
	{
		//マゼンタのボックスの描画
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

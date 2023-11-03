#include "Shoot.h"

Shoot::Shoot()//コンストラクタ
{
	EditPosition().SetX(1100);	//Boxの中心座標のX値
	EditPosition().SetY(400);	//Boxの中心座標のY値

	box_x_half = 16.f;			//Boxの横座標の半径
	box_y_half = 24.f;			//Boxの縦座標の半径

	shoot_speed = 3.f;			//Boxの移動速度

	box_flg = true;
}
Shoot::~Shoot()//デストラクタ
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
		//Boxを作成
		DrawBox(box_left_x, box_left_y, box_right_x, box_right_y, 0x00ffff, TRUE);
	}
}
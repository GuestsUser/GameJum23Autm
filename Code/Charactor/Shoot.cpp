#include "Shoot.h"
#include "SceneAccessor.h"

void ImageMemory(int& handle, const char* fail_name)
{
	try
	{
		handle = LoadGraph(fail_name);
		if (handle == -1)
		{
			throw fail_name;
		}
	}
	catch (const char& err)
	{
		printf("%dがありません", err);
	}
}



Shoot::Shoot()//コンストラクタ
{
	box_x_half = 16.f;			//Boxの横座標の半径
	box_y_half = 24.f;			//Boxの縦座標の半径

	shoot_max_speed = 4.f;		//Boxの移動速度

	ImageMemory(shoot_blue, "Resource/image/blue_shoot.png");
	ImageMemory(shoot_red, "Resource/image/red_shoot.png");
	ImageMemory(shoot_hit_blue, "Resource/image/hit_blue_shoot.png");
	ImageMemory(shoot_hit_red, "Resource/image/hit_red_shoot.png");
	
	box_flg = TRUE;
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
		box_flg = FALSE;
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
		DrawGraphF(box_left_x, box_left_y, shoot_blue, TRUE);
	}
	if ((box_flg == TRUE) && (color == Color::RED))
	{
		//マゼンタのボックスの描画
		DrawGraphF(box_left_x, box_left_y, shoot_red, FALSE);
	}
	if ((box_flg == FALSE) && (color == Color::BLUE))
	{
		DrawGraphF(box_left_x, box_left_y, shoot_hit_blue, TRUE);
		SceneAccessor::GetInstance()->GetCurrentScene()->DestroyObject(this);
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
Color Shoot::GetShootColor()
{
	return color;
}
#pragma once
#include "Charactor.h"
#include "DxLib.h"

#define CAMERA_CENTER_X 480
class Shoot :public Charactor
{
private:
	int box_flg;		//Box表示のOn・Off

	float shoot_speed;	//弾の速度

	float box_x_half;	//BoxのX軸の半径
	float box_y_half;	//BoxのY軸の半径

	int is_left;		//弾が左側で生成されたか判定する変数
public:
	Shoot();	//コンストラクタ
	~Shoot();	//デストラクタ

	void SetX();
	void SetSpeed();

	void Update();	//描画以外の更新に関する処理
	void Draw();	//描画に関する処理
};

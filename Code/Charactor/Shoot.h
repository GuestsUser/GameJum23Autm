#pragma once
#include "Charactor.h"
#include "Player.h"
#include "DxLib.h"
#include "Collision.h"

#define CAMERA_CENTER_X 480
class Shoot :public Charactor
{
private:

	int box_flg;		//Box表示のOn・Off

	float shoot_max_speed;	//弾の最高速度
	float shoot_speed;		//弾の速度

	float box_x_half;	//BoxのX軸の半径
	float box_y_half;	//BoxのY軸の半径

	int shoot_blue;		//青の弾
	int shoot_red;		//赤の弾
	int shoot_hit_blue;	//青の弾のヒット画像
	int shoot_hit_red;	//赤の弾のヒット画像

	int ball_alpha;		//ボールの透明度

	int ball_delete;

	Color color;		//弾の色の識別
	Collision* ball_collision;
	Player* player;

public:
	Shoot();	//コンストラクタ
	~Shoot();	//デストラクタ

	void SetSpeed(float speed);		//スピード値の設定

	void SetBoxColor(Color color_);	//ブロックの色の設定
	Color GetShootColor();

	void Update();					//描画以外の更新に関する処理
	void Draw();					//描画に関する処理
};
#include "DxLib.h"
#include "ConstVal.h"
#include "GameStart.h"

GameStart::GameStart()
	:frame_count(0)
	,is_show(true)
{
	int image = LoadGraph("Resource/image/GameStart.png");

	anim = new SimpleAnimation(image
		, Vector3(float(WINDOW_X) / 2.f, -60.f, 0.f)
		, Vector3(float(WINDOW_X) / 2.f, float(WINDOW_Y) + 60.f, 0.f)
		, 40);

}

GameStart::~GameStart()
{
	delete anim;
}

void GameStart::Update()
{
	//0~19更新 20~39止まる 40~更新
	if ((0 <= frame_count)&&(frame_count <= 19) || 
		40 <= frame_count)
	{
		anim->Update();
	}

	//	アニメーションが終わったら描画を切る
	is_show = anim->GetIsMoving();

	frame_count++;
}

void GameStart::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "%d", frame_count);
	anim->Draw();
}
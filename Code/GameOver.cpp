#include "DxLib.h"
#include "ConstVal.h"
#include "GameOver.h"

GameOver::GameOver()
	:frame_count(0)
	, is_show(true)
	,alpha(255)
{
	int* image = new int[IMAGE_ALL_NUM];
	LoadDivGraph("Resource/image/GameOver.png", IMAGE_ALL_NUM, 8, 1, IMAGE_WIDTH, IMAGE_HEIGHT, image);
	float offset = float(WINDOW_X - 768) / 2;
	offset += float(IMAGE_WIDTH) / 2;

	float start_y = float(-(IMAGE_HEIGHT) / 2);
	for (int i = 0; i < IMAGE_ALL_NUM; i++)
	{
		anims[i] = new SimpleAnimation(image[i],
			Vector3(offset + (IMAGE_WIDTH * i), start_y, 0)
			, Vector3(offset + (IMAGE_WIDTH * i), float(WINDOW_Y) / 2, 0)
			, 50 + (8 * i));
	}

	delete[] image;
}

GameOver::~GameOver()
{
	for (SimpleAnimation* anim : anims)
	{
		delete anim;
	}
}

void GameOver::Update()
{
	for (SimpleAnimation* anim : anims)
	{
		anim->Update();
	}

	//	アニメーションが回り切ったら30フレームかけて消す
	if (anims[IMAGE_ALL_NUM - 1]->GetIsMoving() == false)
	{
		alpha -= int(255 / 30);
	}
	if (alpha < 0)
	{
		//	写らなくなったら終了通知する
		is_show = false;
	}

	frame_count++;
}

void GameOver::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	for (SimpleAnimation* anim : anims)
	{
		anim->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
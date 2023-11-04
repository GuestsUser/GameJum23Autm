#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"
#include"../Worldval.h"

Score::Score()
{
	score = WorldVal::Get<int>("score"); //現在のスコアを入れる
	high_score = WorldVal::Get<int>("highscore");//ハイスコアを入れる
	count = 0;
	SetFontSize(50);
}

void Score::Update()
{
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))//Aボタンが押されたとき次のシーンを入れる
	{
		SetNext(nullptr);
	}
	if (++count > FPS)count = 0;
}

void Score::Draw()
{
	DrawFormatString(345, 100, 0xffffff, "スコア　%03d", *score);
	DrawFormatString(290, 200, 0xffffff, "ハイスコア　%03d", *high_score);
	if(count > (FPS / 2))DrawString(270, 300, "Aボタンでタイトル", 0xffffff);
}
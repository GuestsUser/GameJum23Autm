#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"
#include"../Worldval.h"

Score::Score(int score)
{
	this->score = score; //現在のスコアを入れる
	highscore = *WorldVal::Get<int>("highscore");//ハイスコアを入れる

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
	DrawFormatString(355, 100, 0xffffff, "スコア　%d", score);
	DrawFormatString(305, 200, 0xffffff, "ハイスコア　%d", highscore);
	if(count > (FPS / 2))DrawString(270, 300, "Aボタンでタイトル", 0xffffff);
}
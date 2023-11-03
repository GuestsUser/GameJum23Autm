#include "DxLib.h"
#include "Result.h"
#include"ConstVal.h"
#include"../Worldval.h"

Result::Result(int score)
{
	this->score = score; //現在のスコアを入れる
	high_score = *WorldVal::Get<int>("highscore");//ハイスコアを入れる
	//if (*high_score < score)//現在のスコアがハイスコアを越えてたら
	//{
	//	WorldVal::Del("highscore");//ハイスコアを消す
	//	WorldVal::Set("highscore", new int(score));//新しいハイスコアを作る
	//	high_score = WorldVal::Get<int>("highscore");//ハイスコアを入れる
	//}
	count = 0;
	SetFontSize(50);
}

void Result::Update()
{
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))//Aボタンが押されたとき次のシーンを入れる
	{
		SetNext(nullptr);
	}

	if (++count > FPS)count = 0;
}

void Result::Draw()
{
	DrawFormatString(355, 100, 0xffffff, "スコア　%03d", score);
	DrawFormatString(305, 200, 0xffffff, "ハイスコア　%03d", high_score);
	if(count > (FPS / 2))DrawString(270, 300, "Aボタンでタイトル", 0xffffff);
}
#include "DxLib.h"
#include "Ui.h"
#include"../Worldval.h"

Ui::Ui()
{
	score = 0;
	high_score = *WorldVal::Get<int>("highscore");//ハイスコアを入れる
	SetFontSize(30);
}

Ui::~Ui()
{
	if (score > high_score)
	{
		WorldVal::Del("highscore");//ハイスコアを消す
		WorldVal::Set("highscore", new int(score));//新しいハイスコアを作る
	}
}

void Ui::Update()
{
	if (score > high_score)high_score = score;
}

void Ui::Draw()
{
	DrawFormatString(160, 20, 0xffffff, "スコア　:　%03d　　　　　ハイスコア　:　%03d", score,high_score);
}
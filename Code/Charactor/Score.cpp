#include "DxLib.h"
#include"Score.h"
#include"../Worldval.h"


Score::Score()
{
	score = 0;
	high_score = *WorldVal::Get<int>("highscore");//ハイスコアを入れる
	SetFontSize(30);
}

Score::~Score()
{
	if (score > high_score)
	{
		WorldVal::Del("highscore");//ハイスコアを消す
		WorldVal::Set("highscore", new int(score));//新しいハイスコアを作る
	}
}

void Score::Update()
{
	if (score > high_score)
	{
		high_score = score;
	}
}

void Score::Draw()
{
	DrawFormatString(160, 10, 0xffffff, "スコア　:　%03d　　　　　ハイスコア　:　%03d", score, high_score);
}
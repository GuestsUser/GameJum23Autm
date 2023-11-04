#include "DxLib.h"
#include "Ui.h"
#include"../Worldval.h"

Ui::Ui()
{
	score = WorldVal::Get<int>("score");//スコアを取得;
	*score = 0;
	high_score = WorldVal::Get<int>("highscore");//ハイスコアを取得
	SetFontSize(30);
}

Ui::~Ui()
{
}

void Ui::AddScore(bool point)
{
	if (point)
	{
		if(++*score > 999)*score = 999;
	}
}

void Ui::Update()
{
	if (*score > *high_score)*high_score = *score;//スコアがハイスコアを越えていたらハイスコアを更新
}

void Ui::Draw()
{
	DrawFormatString(160, 20, 0xffffff, "スコア　:　%03d　　　　　ハイスコア　:　%03d", *score, *high_score);
}
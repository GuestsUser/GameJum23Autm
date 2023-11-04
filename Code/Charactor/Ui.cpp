#include "DxLib.h"
#include "Ui.h"
#include"../Worldval.h"

Ui::Ui()
{
	score = 0;
	high_score = *WorldVal::Get<int>("highscore");//ハイスコアを取得
	SetFontSize(30);
}

Ui::~Ui()
{
	if (score > high_score)//スコアがハイスコアを越えていたら
	{
		WorldVal::Del("highscore");//ハイスコアを消す
		WorldVal::Set("highscore", new int(score));//新しいハイスコアを登録
	}
}

void Ui::Update()
{
	if (score > high_score)high_score = score;//スコアがハイスコアを越えていたらハイスコアを更新
}

void Ui::Draw()
{
	DrawFormatString(160, 20, 0xffffff, "スコア　:　%03d　　　　　ハイスコア　:　%03d", score,high_score);
}
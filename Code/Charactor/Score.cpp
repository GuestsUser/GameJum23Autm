#include "DxLib.h"
#include"Score.h"

Score::Score()
{
	score = 10;
}

void Score::Update()
{
}

void Score::Draw()
{
	DrawFormatString(355, 100, 0xffffff, "スコア　:　%d", score);
}
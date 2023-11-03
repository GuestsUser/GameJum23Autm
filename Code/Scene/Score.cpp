#include "DxLib.h"
#include "Score.h"

Score::Score(int score)
{
	this->score = score;
}

void Score::Update()
{

}

void Score::Draw()
{
	DrawFormatString(100, 100, 0xffffff, "スコア　%d", score);
}
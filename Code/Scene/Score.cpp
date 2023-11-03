#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"
#include"../Worldval.h"

Score::Score(int score)
{
	this->score = score;
	highscore = WorldVal::Get<int>("highscore");

	if (*highscore < score)
	{
		WorldVal::Del("highscore");
		WorldVal::Set("highscore", new int(score));
		highscore = WorldVal::Get<int>("highscore");
	}
}

void Score::Update()
{

}

void Score::Draw()
{
	DrawFormatString(WINDOW_X / 2, WINDOW_Y / 2, 0xffffff, "スコア　%d", score);
	DrawFormatString(WINDOW_X / 2, (WINDOW_Y / 2) + 30, 0xffffff, "ハイスコア　%d", *highscore);
}
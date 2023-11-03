#include "DxLib.h"
#include"Score.h"
#include"../Worldval.h"


Score::Score()
{
	score = 0;
	high_score = *WorldVal::Get<int>("highscore");//�n�C�X�R�A������
	SetFontSize(30);
}

Score::~Score()
{
	if (score > high_score)
	{
		WorldVal::Del("highscore");//�n�C�X�R�A������
		WorldVal::Set("highscore", new int(score));//�V�����n�C�X�R�A�����
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
	DrawFormatString(160, 10, 0xffffff, "�X�R�A�@:�@%03d�@�@�@�@�@�n�C�X�R�A�@:�@%03d", score, high_score);
}
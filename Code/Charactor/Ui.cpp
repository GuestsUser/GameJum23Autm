#include "DxLib.h"
#include "Ui.h"
#include"../Worldval.h"

Ui::Ui()
{
	score = WorldVal::Get<int>("score");//�X�R�A���擾;
	*score = 0;
	high_score = WorldVal::Get<int>("highscore");//�n�C�X�R�A���擾
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
	if (*score > *high_score)*high_score = *score;//�X�R�A���n�C�X�R�A���z���Ă�����n�C�X�R�A���X�V
}

void Ui::Draw()
{
	DrawFormatString(160, 20, 0xffffff, "�X�R�A�@:�@%03d�@�@�@�@�@�n�C�X�R�A�@:�@%03d", *score, *high_score);
}
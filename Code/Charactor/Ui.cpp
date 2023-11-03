#include "DxLib.h"
#include "Ui.h"
#include"../Worldval.h"

Ui::Ui()
{
	score = 0;
	high_score = *WorldVal::Get<int>("highscore");//�n�C�X�R�A������
	SetFontSize(30);
}

Ui::~Ui()
{
	if (score > high_score)
	{
		WorldVal::Del("highscore");//�n�C�X�R�A������
		WorldVal::Set("highscore", new int(score));//�V�����n�C�X�R�A�����
	}
}

void Ui::Update()
{
	if (score > high_score)high_score = score;
}

void Ui::Draw()
{
	DrawFormatString(160, 20, 0xffffff, "�X�R�A�@:�@%03d�@�@�@�@�@�n�C�X�R�A�@:�@%03d", score,high_score);
}
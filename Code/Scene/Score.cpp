#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"
#include"../Worldval.h"

Score::Score()
{
	score = WorldVal::Get<int>("score"); //���݂̃X�R�A������
	high_score = WorldVal::Get<int>("highscore");//�n�C�X�R�A������
	count = 0;
	SetFontSize(50);
}

void Score::Update()
{
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))//A�{�^���������ꂽ�Ƃ����̃V�[��������
	{
		SetNext(nullptr);
	}
	if (++count > FPS)count = 0;
}

void Score::Draw()
{
	DrawFormatString(345, 100, 0xffffff, "�X�R�A�@%03d", *score);
	DrawFormatString(290, 200, 0xffffff, "�n�C�X�R�A�@%03d", *high_score);
	if(count > (FPS / 2))DrawString(270, 300, "A�{�^���Ń^�C�g��", 0xffffff);
}
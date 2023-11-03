#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"
#include"../Worldval.h"

Score::Score(int score)
{
	this->score = score; //���݂̃X�R�A������
	highscore = *WorldVal::Get<int>("highscore");//�n�C�X�R�A������

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
	DrawFormatString(355, 100, 0xffffff, "�X�R�A�@%d", score);
	DrawFormatString(305, 200, 0xffffff, "�n�C�X�R�A�@%d", highscore);
	if(count > (FPS / 2))DrawString(270, 300, "A�{�^���Ń^�C�g��", 0xffffff);
}
#include "DxLib.h"
#include "Result.h"
#include"ConstVal.h"
#include"../Worldval.h"

Result::Result(int score)
{
	this->score = score; //���݂̃X�R�A������
	high_score = *WorldVal::Get<int>("highscore");//�n�C�X�R�A������
	//if (*high_score < score)//���݂̃X�R�A���n�C�X�R�A���z���Ă���
	//{
	//	WorldVal::Del("highscore");//�n�C�X�R�A������
	//	WorldVal::Set("highscore", new int(score));//�V�����n�C�X�R�A�����
	//	high_score = WorldVal::Get<int>("highscore");//�n�C�X�R�A������
	//}
	count = 0;
	SetFontSize(50);
}

void Result::Update()
{
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A))//A�{�^���������ꂽ�Ƃ����̃V�[��������
	{
		SetNext(nullptr);
	}

	if (++count > FPS)count = 0;
}

void Result::Draw()
{
	DrawFormatString(355, 100, 0xffffff, "�X�R�A�@%03d", score);
	DrawFormatString(305, 200, 0xffffff, "�n�C�X�R�A�@%03d", high_score);
	if(count > (FPS / 2))DrawString(270, 300, "A�{�^���Ń^�C�g��", 0xffffff);
}
#include "DxLib.h"
#include "Game.h"
#include "Title.h"

#include "Controller.h"
Title::Title()
{
	
}

Title::~Title()
{

}

//�X�V����
void Title::Update()
{
	//BGM�̍Đ�
	
	//"A"�L�[�������ꂽ���ǂ���
	if (Controller::OnInputA())
	{
		//BGM�̒�~

		//SE�̍Đ�

		//���C����ʂւ̑J��
		SetNext(new Game());
	}
	
	
}

//�`�ʏ���
void Title::Draw()
{
	//�w�i�̕`��
	
	//�^�C�g���̕`��
	SetFontSize(130);
	DrawString(15, 100, "ONE BUTTON MAN", GetColor(0, 0, 255));
	SetFontSize(70);
	DrawString(250, 340, "push   button", GetColor(255, 0, 0));
	DrawString(250, 340, "     A       ", GetColor(255, 0, 0));

}
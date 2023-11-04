#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager/SoundManager.h"

Title::Title()
{
	Title_Image = LoadGraph("Resource/image/Title.png");
	Title_BGM = SoundManager::GetBGM("Title");
	Title_SE = SoundManager::GetSE("Decision");
}

Title::~Title()
{

}

//�X�V����
void Title::Update()
{
	//BGM�̍Đ�
	SoundManager::PlayBGM(Title_BGM);

	//"A"�L�[�������ꂽ���ǂ���
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		//SE�̍Đ�
		SoundManager::PlaySE(Title_SE);

		//���C����ʂւ̑J��
		SetNext(new Game());
	}
	
	
}

//�`�ʏ���
void Title::Draw()
{
	//�w�i�̕`��
	DrawGraph(0,0,Title_Image,TRUE);

	//�^�C�g���̕`��
	SetFontSize(130);
	DrawString(15, 100, "ONE BUTTON MAN", GetColor(255, 255, 255));
	SetFontSize(70);
	DrawString(250, 340, "push   button", GetColor(255, 0, 0));
	DrawString(250, 340, "     A       ", GetColor(255, 0, 0));

}
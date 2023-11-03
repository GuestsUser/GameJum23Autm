#include "DxLib.h"
#include "Game.h"
#include "Title.h"

Title::Title()
{
	
}

Title::~Title()
{

}

void Title::Update()
{
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		SetNext(new Game());
	}
}

void Title::Draw()
{
	DrawBox(0, 0, 960, 480, GetColor(255, 255, 255), TRUE);
	//LoadGraph("Resouce/image/ashiato_pink.png", TRUE);
	
	SetFontSize(100);
	DrawString(140, 100, "ONE BUTTON MAN", GetColor(0, 0, 255));
	SetFontSize(60);
	DrawString(300, 320, "PUSH   BUTTON", GetColor(255, 0, 0));
	DrawString(300, 320, "     A       ", GetColor(255, 0, 0));

}
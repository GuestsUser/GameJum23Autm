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
	SetFontSize(100);

	DrawString(15, 200, "ƒ^ƒCƒgƒ‹‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢(‰¼)", GetColor(0, 255, 0));

	DrawString(460, 600, "PUSH   BUTTON", GetColor(255, 255, 255));
	DrawString(460, 600, "     A       ", GetColor(255, 0, 0 ));

}
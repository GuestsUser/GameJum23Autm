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

//XVˆ—
void Title::Update()
{
	//BGM‚ÌÄ¶
	SoundManager::PlayBGM(Title_BGM);

	//"A"ƒL[‚ª‰Ÿ‚³‚ê‚½‚©‚Ç‚¤‚©
	if (CheckHitKey(KEY_INPUT_A) != 0)
	{
		//SE‚ÌÄ¶
		SoundManager::PlaySE(Title_SE);

		//ƒƒCƒ“‰æ–Ê‚Ö‚Ì‘JˆÚ
		SetNext(new Game());
	}
	
	
}

//•`Êˆ—
void Title::Draw()
{
	//”wŒi‚Ì•`Ê
	DrawGraph(0,0,Title_Image,TRUE);

	//ƒ^ƒCƒgƒ‹‚Ì•`‰æ
	SetFontSize(130);
	DrawString(15, 100, "ONE BUTTON MAN", GetColor(255, 255, 255));
	SetFontSize(70);
	DrawString(250, 340, "push   button", GetColor(255, 0, 0));
	DrawString(250, 340, "     A       ", GetColor(255, 0, 0));

}
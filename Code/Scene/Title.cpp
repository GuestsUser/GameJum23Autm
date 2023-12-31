#include "DxLib.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager/SoundManager.h"

#include "Controller.h"
Title::Title()
{
	Title_Image = LoadGraph("Resource/image/Title.png");
	Title_BGM = SoundManager::GetBGM("Title");
	Title_SE = SoundManager::GetSE("Decision");
}

Title::~Title()
{

}

//更新処理
void Title::Update()
{
	//BGMの再生
	SoundManager::PlayBGM(Title_BGM);

	//"A"キーが押されたかどうか
	if (Controller::OnInputA())
	{
		//SEの再生
		SoundManager::PlaySE(Title_SE);

		//メイン画面への遷移
		SetNext(new Game());
	}
	
	
}

//描写処理
void Title::Draw()
{
	//背景の描写
	DrawGraph(0,0,Title_Image,TRUE);

	//タイトルの描画
	SetFontSize(130);
	DrawString(15, 100, "ONE BUTTON MAN", GetColor(255, 255, 255));
	SetFontSize(70);
	DrawString(250, 340, "push   button", GetColor(255, 0, 0));
	DrawString(250, 340, "     A       ", GetColor(255, 0, 0));

}
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

//更新処理
void Title::Update()
{
	//BGMの再生
	
	//"A"キーが押されたかどうか
	if (Controller::OnInputA())
	{
		//BGMの停止

		//SEの再生

		//メイン画面への遷移
		SetNext(new Game());
	}
	
	
}

//描写処理
void Title::Draw()
{
	//背景の描写
	
	//タイトルの描画
	SetFontSize(130);
	DrawString(15, 100, "ONE BUTTON MAN", GetColor(0, 0, 255));
	SetFontSize(70);
	DrawString(250, 340, "push   button", GetColor(255, 0, 0));
	DrawString(250, 340, "     A       ", GetColor(255, 0, 0));

}
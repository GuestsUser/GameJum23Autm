﻿//この部分のコメントアウトを外すとデバッグ終了時にnewの開放し忘れをメモリ数で通知してくれる
//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>
//#define new  ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )

#include "DxLib.h"
#include "ConstVal.h"
#include "SceneManager.h"
#include "Game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //デバッグ表示を可能にする
	ChangeWindowMode(true);
	SetEnableXAudioFlag(true); //3dサウンドを使用する設定

	if (DxLib_Init() == -1) { return -1; }		//初期化と異常が認められた場合の終了
	SetCreate3DSoundFlag(true); //読み込むサウンドを3dサウンドとして扱う
	Set3DSoundOneMetre(1.0f); //3d空間上での距離単位設定、1=1m

	int fps = 1000000 / FPS; //割る値を変えると1秒間に行う処理回数を変更できる
	LONGLONG now = GetNowHiPerformanceCount();
	LONGLONG old = now;

	//ウィンドウの初期設定
	SetWindowText("かちかち"); //画面タイトル設定
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); //画面モードの設定
	SetBackgroundColor(0, 0, 0); //画面の背景色の設定
	SetDrawScreen(DX_SCREEN_BACK);
	SceneManager* scm = new SceneManager(new Game()); //セレクト画面が完成したから最初に実行するシーンはタイトルに固定、其々のシーンに飛ばす処理はScene_Select.cppのswitch文を確認
	
	while (ProcessMessage() == 0 && (!CheckHitKey(KEY_INPUT_ESCAPE))) { //GetKeyシステム使用例、backボタンが押された瞬間にfalseとなる
		//_RPTF1(_CRT_WARN, "%s\n", "test"); //デバッグ表示

		now = GetNowHiPerformanceCount(); //現在時刻の取得
		if (now - old > fps) { //前フレームの現在時刻との差が実行タイミングになっていた場合ゲーム処理、描写の実行
			old = now - (now - old - fps); //差が実行タイミング以上だった場合そのままoldに現在時刻を入れると切り捨てられてしまうのでoldから実行タイミング超過分を引く事で超過分を加味した形にする
			ClearDrawScreen(); //画面の初期化
			if (!scm->Update()) { break; } //ウィンドウを閉じる指示を出されてたら終了
			scm->Draw(); //画面描写
		}
		ScreenFlip();
	}
	delete scm;
	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;
}
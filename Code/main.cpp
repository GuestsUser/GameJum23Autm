//この部分のコメントアウトを外すとデバッグ終了時にnewの開放し忘れをメモリ数で通知してくれる
//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>
//#define new  ::new( _NORMAL_BLOCK, __FILE__, __LINE__ )

#include "DxLib.h"
#include "ConstVal.h"
#include "SceneManager.h"
#include "Title.h"
#include "Game.h"
#include "Worldval.h"
#include "SoundManager/SoundManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //デバッグ表示を可能にする
	SetAlwaysRunFlag(true);
	ChangeWindowMode(true);

	int fps = 1000000 / FPS; //割る値を変えると1秒間に行う処理回数を変更できる
	LONGLONG now = GetNowHiPerformanceCount();
	LONGLONG old = now;

	//ウィンドウの初期設定
	SetWindowText("1ボタン"); //画面タイトル設定
	SetGraphMode(WINDOW_X, WINDOW_Y, 32); //画面モードの設定
	SetBackgroundColor(0, 0, 0); //画面の背景色の設定
	SetDrawScreen(DX_SCREEN_BACK);

	if (DxLib_Init() == -1) { return -1; }		//初期化と異常が認められた場合の終了


	SoundManager::GetInstance();
	WorldVal::SetUp();
	WorldVal::Set("highscore", new int(0));
	WorldVal::Set("score", new int(0));
	SoundManager::GetInstance();
	SceneManager* scm = new SceneManager(new Title()); //セレクト画面が完成したから最初に実行するシーンはタイトルに固定、其々のシーンに飛ばす処理はScene_Select.cppのswitch文を確認
	

	while (ProcessMessage() == 0 && (!CheckHitKey(KEY_INPUT_ESCAPE))) { //GetKeyシステム使用例、backボタンが押された瞬間にfalseとなる
		//_RPTF1(_CRT_WARN, "%s\n", "test"); //デバッグ表示

		try
		{
			now = GetNowHiPerformanceCount(); //現在時刻の取得
			if (now - old > fps) { //前フレームの現在時刻との差が実行タイミングになっていた場合ゲーム処理、描写の実行
				old = now; //差が実行タイミング以上だった場合そのままoldに現在時刻を入れると切り捨てられてしまうのでoldから実行タイミング超過分を引く事で超過分を加味した形にする
				ClearDrawScreen(); //画面の初期化
				if (!scm->Update()) { break; } //ウィンドウを閉じる指示を出されてたら終了
				scm->Draw(); //画面描写
			}
			ScreenFlip();
		}
		catch (const char* error_message)
		{
			FILE* fp = NULL;

			DATEDATA data;

			GetDateTime(&data);
			//ファイルオープン
			fopen_s(&fp, "ErrorLog.txt", "a");
			//エラーデータの書き込み
			fprintf_s(fp, "%s",error_message);

			return -1;
		}
	}
	delete scm;
	WorldVal::Destruct();

	DxLib_End();// ＤＸライブラリ使用の終了処理
	return 0;
}

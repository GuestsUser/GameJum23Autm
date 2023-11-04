#include "SceneManager.h"
#include "./Scene/Scene.h"
#include "SceneAccessor.h"
#include "Controller.h"

SceneManager::SceneManager(Scene* ini)
	:run(ini)
{
	SceneAccessor::Initialize(ini);
	accessor_insctance = SceneAccessor::GetInstance();
	controller = new Controller();
}

SceneManager::~SceneManager()
{
	delete controller;
}

bool SceneManager::Update() {
	//while (true) { //移行後のシーンも一度はupdateを呼び出す為ループ仕様
	//	run->Update(); //update実行
	//	Scene* next = run->GetNext(); //次シーンの取得
	//	if (run == next) { break; } //継続だったらループ抜け

	//	delete run; //移行を命令されたら現在シーンの削除
	//	if (next == nullptr) { run = nullptr; return false; } //終了処理
	//	run = next; //実行するシーンを次回の物に更新
	//}
	while (true) { //移行後のシーンはupdateの呼び出しを行わない仕様
		run->Update(); //update実行
		Scene* next = run->GetNext(); //次シーンの取得
		controller->Update();
		if (run == next) { break; } //継続だったらループ抜け

		delete run; //移行を命令されたら現在シーンの削除
		accessor_insctance->SetCurrentScene(next);	//	アクセサのシーンを更新
		run = next; //実行するシーンを次回の物に更新
		run->SortBasedOnPriority();//	次回のシーンの描画順を整える
		if (run == nullptr) { return false; } //次回の物に何も入ってなかった場合ウィンドウを閉じる命令を通知する
	}
	return true; //Drawに処理を移す
}

void SceneManager::Draw() { run->Draw(); }
#pragma once
class SceneAccessor;
class Scene;
class Controller;

class SceneManager { //シーン管理用クラス、メインに一つ作ってUpdateとDrawを呼び出す事で使用する
	Scene* run; //実行するシーン実体が入っている
	SceneAccessor* accessor_insctance;
	Controller* controller;
public:
	SceneManager(Scene* ini); //最初に読み込みたいシーンのインスタンスを引数に入れる
	~SceneManager();

	bool Update(); //実行するシーンの処理を実行する、ウィンドウを閉じる場合返り値がfalseになる
	void Draw(); //実行シーンの描写を行う
};
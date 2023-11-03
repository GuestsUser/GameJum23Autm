#pragma once
#include "Charactor/Charactor.h"
#include <vector>

class Scene { //このクラスを継承してシーン処理をUpdateに、描写処理をDrawに定義する
public:
	Scene() :next(this) {} //初期化時に自身を入れておく
	virtual ~Scene(); //継承可能なクラスはデストラクタに仮想関数指定がないと親クラスのデストラクタしか呼び出されないのでvirtual指定をしている
	
	virtual void Update(); //毎フレーム実行する処理関数
	virtual void Draw();   //毎フレーム実行する描写関数
	virtual void FullReset() {} //完全リセットしたい時の関数
	virtual void Reset() {} //新しいゲーム等の理由でシーンリセットしたくなった時の関数

	bool SetNext(Scene* set){ //シーンチェンジ用、引数に次シーンの実体を入れる
		//if (next != this) { return false; } //既に次シーンの指定がなされている場合失敗
		next = set; //次シーンを設定
		return true; //成功を返す
	}
	Scene* GetNext() { return next; } //次シーンの取得

	template <class T>
	T* CreateObject(const Vector3& position)
	{
		//	GameObjectの生成
		T* new_instance = new T();
		Charactor* new_object = dynamic_cast<Charactor*>(new_instance);

		//	Charactorを派生していない場合管理できないので破棄する
		if (new_object == nullptr)
		{
			delete new_instance;
			return nullptr;
		}

		//	GameObjectの登録
		scene_objects.push_back(new_object);


		//	位置設定
		new_object->EditPosition() = position;

		return new_instance;

	}

	void DestroyObject(Charactor* object);

	void DestroyAllObjects();

private:
	Scene* next; //シーン遷移する場合次シーン実体、そのままの場合自身、ウィンドウを閉じる場合nullptrが入る
	std::vector<Charactor*> scene_objects;
};
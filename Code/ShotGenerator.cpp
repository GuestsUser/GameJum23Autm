#include "DxLib.h"

#include "ShotGenerator.h"
#include "Scene.h"
#include "SceneAccessor.h"
#include "Shoot.h"

#include "ConstVal.h"

ShotGenerator::ShotGenerator() :count(0), spawTime(30) {
	baseSpeed = WINDOW_X / 2 / 150; //画面端から画面中央まで150フレームで到達するスピード
	edit = SceneAccessor::GetInstance();
}

void ShotGenerator::Update() {
	if (count < spawTime) { //スポーンタイミングに達していない場合
		++count;
		return;
	}
	
	count = 0; //ここにこれればスポーンタイミング、カウントリセット

	Place placeMode = (Place)GetRand((int)Place::len - 1); //配置形式の作成
	Type typeMode = (Type)GetRand((int)Type::len - 1);

	if (placeMode == Place::normal) {
		ShotGenerat(Place::left, typeMode);
		ShotGenerat(Place::right, typeMode);
	}
	else { ShotGenerat(placeMode, typeMode); }
}

void ShotGenerator::ShotGenerat(Place place, Type type) { //ここに書いている数値は仮の物
	Vector3 position = Vector3();
	float speed = 1;

	position.SetY(WINDOW_Y - 64);
	if (type == Type::up) { position.SetY(64); }

	if (type == Type::highSpeed) { speed = 2; }
	if (type == Type::lowSpeed) { speed = 0.5; }

	position.SetX(-32);
	if (place == Place::right) { 
		position.SetX(WINDOW_X + 32);
		speed *= -1;
	}

	Shoot* shot=edit->GetCurrentScene()->CreateObject<Shoot>(position);

	shot->SetSpeed(baseSpeed * speed);
	shot->SetBoxColor(Color(GetRand(1)));
}

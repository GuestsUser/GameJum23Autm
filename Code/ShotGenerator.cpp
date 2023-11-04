#include "DxLib.h"

#include "ShotGenerator.h"
#include "Scene.h"
#include "SceneAccessor.h"
#include "Shoot.h"


ShotGenerator::ShotGenerator() :count(0), spawTime(60), highLevelSpan(6) {
	baseSpeed = WINDOW_X / 2 / 150; //画面端から画面中央まで150フレームで到達するスピード
	edit = SceneAccessor::GetInstance();

	current_pattern = GetRand(4);
	left_upper = 4;
	left_footer = 4;
	right_upper = 5;
	right_footer = 5;
}

void ShotGenerator::Update() {
	++count;

	if (count % spawTime != 0) { //スポーンタイミングではない場合
		return;
	}

	//ここまで来れればスポーンタイミングになっている
	//Place placeMode = (Place)GetRand((int)Place::len - 1); //配置形式の作成
	//Type typeMode = Type::normal;

	//if ((count / spawTime) % highLevelSpan == 0) { typeMode = (Type)GetRand((int)Type::len - 1); } //ハイレベルのタイミングであればType抽選

	//if (placeMode == Place::normal) {
	//	ShotGenerat(Place::left, typeMode);
	//	ShotGenerat(Place::right, typeMode);
	//}
	//else { ShotGenerat(placeMode, typeMode); }

	GenerationBasedOnPattern();
	left_upper--;
	left_footer--;
	right_upper++;
	right_footer++;
	
	if (left_upper < 0)
	{
		current_pattern = GetRand(4);
		left_upper = 4;
		left_footer = 4;
		right_upper = 5;
		right_footer = 5;
	}
}

void ShotGenerator::ShotGenerat(Place place, Type type) { //ここに書いている数値は仮の物
	Vector3 position = Vector3();
	float speed = 1;

	position.SetY(430);
	if (type == Type::up) { position.SetY(360); }

	if (type == Type::highSpeed) { speed = 2; }
	if (type == Type::lowSpeed) { speed = 0.5; }

	position.SetX(-32);
	if (place == Place::right) {
		position.SetX(WINDOW_X + 32);
		speed *= -1;
	}

	Shoot* shot = edit->GetCurrentScene()->CreateObject<Shoot>(position);

	shot->SetSpeed(baseSpeed * speed);
	shot->SetBoxColor(Color(GetRand(1)));
}

void ShotGenerator::GenerationBasedOnPattern()
{
	Vector3 position;
	Shoot* shot;

	//	左上
	position = Vector3(LEFT, UP, 0);
	shot = edit->GetCurrentScene()->CreateObject<Shoot>(position);
	shot->SetBoxColor(Color(generation_patterns[current_pattern][0][left_upper]));
	shot->SetSpeed(baseSpeed);

	//	右上
	position = Vector3(RIGHT, UP, 0);
	shot = edit->GetCurrentScene()->CreateObject<Shoot>(position);
	shot->SetBoxColor(Color(generation_patterns[current_pattern][0][right_upper]));
	shot->SetSpeed(-baseSpeed);

	//	左下
	position = Vector3(LEFT, FOOT, 0);
	shot = edit->GetCurrentScene()->CreateObject<Shoot>(position);
	shot->SetBoxColor(Color(generation_patterns[current_pattern][1][left_footer]));
	shot->SetSpeed(baseSpeed);

	//	右下
	position = Vector3(RIGHT, FOOT, 0);
	shot = edit->GetCurrentScene()->CreateObject<Shoot>(position);
	shot->SetBoxColor(Color(generation_patterns[current_pattern][1][right_footer]));
	shot->SetSpeed(-baseSpeed);
}
#pragma once
#include "Charactor.h"

class SceneAccessor;

class ShotGenerator :public Charactor {
	enum class Place { normal, left, right, len }; //配置の形式、normalなら左右に、left、rightならそちらのみに
	enum class Type { normal, up, highSpeed, lowSpeed, len }; //normalなら通常の高さ、upで高い位置、speed系は動作速度が変化する

	int count; //経過時間記録
	int spawTime; //出現タイミング
	int highLevelSpan; //normal以外のtypeを出現させる抽選を行うタイミング
	float baseSpeed; //速度の基準値

	SceneAccessor* edit;

	void ShotGenerat(Place place, Type type);

public:
	ShotGenerator();

	void Update();
};
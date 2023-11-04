#pragma once
#include "Charactor.h"
#include "ConstVal.h"
#define LEFT (0 - 32)
#define RIGHT (WINDOW_X + 32)
#define UP	 (360)
#define FOOT (430)

class SceneAccessor;


class ShotGenerator :public Charactor {

	const int generation_patterns[5][2][10] =
	{
		{
			{9,0,9,9,9,9,9,9,0,9},
			{9,0,1,1,9,9,1,1,0,9}
		},
		{
			{9,1,1,9,9,9,9,1,0,9},
			{9,9,1,0,1,1,0,1,9,9}
		},
		{
			{0,9,9,9,1,0,9,9,9,1},
			{9,0,0,1,0,1,0,1,1,9}
		},
		{
			{9,9,9,9,9,9,9,9,9,9},
			{9,0,0,0,9,9,1,0,1,0}
		},
		{
			{9,9,9,1,9,9,0,9,9,9},
			{1,0,9,1,9,9,0,9,1,0}
		},
	};

	enum class Place { normal, left, right, len }; //配置の形式、normalなら左右に、left、rightならそちらのみに
	enum class Type { normal, up, highSpeed, lowSpeed, len }; //normalなら通常の高さ、upで高い位置、speed系は動作速度が変化する

	int count; //経過時間記録
	int spawTime; //出現タイミング
	int highLevelSpan; //normal以外のtypeを出現させる抽選を行うタイミング
	float baseSpeed; //速度の基準値

	SceneAccessor* edit;

	void ShotGenerat(Place place, Type type);


	void GenerationBasedOnPattern();
	int current_pattern;
	int left_upper;
	int right_upper;
	int left_footer;
	int right_footer;

public:
	ShotGenerator();

	void Update();
};
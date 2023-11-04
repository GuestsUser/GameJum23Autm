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

	enum class Place { normal, left, right, len }; //�z�u�̌`���Anormal�Ȃ獶�E�ɁAleft�Aright�Ȃ炻����݂̂�
	enum class Type { normal, up, highSpeed, lowSpeed, len }; //normal�Ȃ�ʏ�̍����Aup�ō����ʒu�Aspeed�n�͓��쑬�x���ω�����

	int count; //�o�ߎ��ԋL�^
	int spawTime; //�o���^�C�~���O
	int highLevelSpan; //normal�ȊO��type���o�������钊�I���s���^�C�~���O
	float baseSpeed; //���x�̊�l

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
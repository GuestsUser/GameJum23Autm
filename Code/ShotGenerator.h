#pragma once
#include "Charactor.h"

class SceneAccessor;

class ShotGenerator :public Charactor {
	enum class Place { normal, left, right, len }; //�z�u�̌`���Anormal�Ȃ獶�E�ɁAleft�Aright�Ȃ炻����݂̂�
	enum class Type { normal, up, highSpeed, lowSpeed, len }; //normal�Ȃ�ʏ�̍����Aup�ō����ʒu�Aspeed�n�͓��쑬�x���ω�����

	int count; //�o�ߎ��ԋL�^
	int spawTime; //�o���^�C�~���O
	int highLevelSpan; //normal�ȊO��type���o�������钊�I���s���^�C�~���O
	float baseSpeed; //���x�̊�l

	SceneAccessor* edit;

	void ShotGenerat(Place place, Type type);

public:
	ShotGenerator();

	void Update();
};
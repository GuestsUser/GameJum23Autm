#pragma once
#include "OriginMath.h"
#include "DxLib.h"

enum class Color
{
	RED,	//( 0 )
	BLUE	//( 1 )
};

class Charactor { //�Q�[�����ɓo�ꂷ��Œ���̃L�����N�^�[�A�e��L�����͂�����p�����ēo�ꂳ���Ăق���
	Vector3 pos;
public:
	Charactor() :pos(Vector3()) {}
	virtual ~Charactor() {}

	virtual void Update() {}
	virtual void Draw() { DrawString(0, 0, "test", 0xfFFFff); }

	const Vector3& ReadPosition() const { return pos; } //�ǂݏo����p�Ń|�W�V�����̎擾
	Vector3& EditPosition() { return pos; } //�ҏW�\�Ȍ`���Ń|�W�V�����̎擾
};
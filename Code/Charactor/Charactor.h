#pragma once
#include "OriginMath.h"
#include "Object.h"

class Charactor	:public Object { //�Q�[�����ɓo�ꂷ��Œ���̃L�����N�^�[�A�e��L�����͂�����p�����ēo�ꂳ���Ăق���
	Vector3 pos;
public:
	Charactor() :pos(Vector3()) {}
	virtual ~Charactor() {}

	virtual void Update() override{}
	virtual void Draw() override{}

	const Vector3& ReadPosition() const { return pos; } //�ǂݏo����p�Ń|�W�V�����̎擾
	Vector3& EditPosition() { return pos; } //�ҏW�\�Ȍ`���Ń|�W�V�����̎擾
};
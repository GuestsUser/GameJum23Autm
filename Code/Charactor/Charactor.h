#pragma once
#include "OriginMath.h"
#include "DxLib.h"

enum class Color
{
	RED,	//( 0 )
	BLUE	//( 1 )
};

class Charactor { //�Q�[�����ɓo�ꂷ��Œ���̃L�����N�^�[�A�e��L�����͂�����p�����ēo�ꂳ���Ăق���
	int draw_priority;
	Vector3 pos;
public:
	Charactor(int in_draw_priority = 99) :pos(Vector3()), draw_priority(in_draw_priority) {}
	virtual ~Charactor() {}

	virtual void Update() {}
	virtual void Draw() {}

	const Vector3& ReadPosition() const { return pos; } //�ǂݏo����p�Ń|�W�V�����̎擾
	Vector3& EditPosition() { return pos; } //�ҏW�\�Ȍ`���Ń|�W�V�����̎擾

	//	�`��D��x�̌��J(�Ⴂ�ق����珇�ɕ`�� �w�i��0)
	void SetDrawPriority(int in_draw_priority) { draw_priority = in_draw_priority; }
	int GetDrawPriority() { return draw_priority; }
};
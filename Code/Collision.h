#pragma once
#include "OriginMath.h"
#include <deque>


class Charactor;

class Collision {
	static std::deque<Collision*> list; //�V�[���S�ẴR���W������ێ�����

	Charactor* parent; //���̃R���W������ێ�����L�����N�^�[�Q�Ƃ�����
	Vector3 size; //�R���W�����T�C�Y�A���a�T�C�Y��z��A�܂���ۂ̐�L����-size�`size�܂�
	Vector3 relativePos; //parent�̃|�W�V�������N�_�ɂǂ�ʗ���Ă��邩���L�^
public:
	Collision(Charactor* parent, Vector3 size = Vector3(1, 1, 1), Vector3 relativePos = Vector3());
	~Collision();

	Charactor* HitCheck(); //�q�b�g�`�F�b�N���s���A�q�b�g���������ꍇ�q�b�g����Charactor��Ԃ�
};
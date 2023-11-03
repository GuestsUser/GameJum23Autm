#pragma once
#include "Charactor.h"
#include "DxLib.h"

#define CAMERA_CENTER_X 480
class Shoot :public Charactor
{
private:
	int box_flg;		//Box�\����On�EOff

	float shoot_speed;	//�e�̑��x

	float box_x_half;	//Box��X���̔��a
	float box_y_half;	//Box��Y���̔��a

	int is_left;		//�e�������Ő������ꂽ�����肷��ϐ�
public:
	Shoot();	//�R���X�g���N�^
	~Shoot();	//�f�X�g���N�^

	void SetX();
	void SetSpeed();

	void Update();	//�`��ȊO�̍X�V�Ɋւ��鏈��
	void Draw();	//�`��Ɋւ��鏈��
};

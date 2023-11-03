#pragma once
#include "Charactor.h"
#include "DxLib.h"

#define CAMERA_CENTER_X 480
class Shoot :public Charactor
{
private:
	int box_flg;		//Box�\����On�EOff

	float shoot_max_speed;	//�e�̍ō����x
	float shoot_speed;		//�e�̑��x

	float box_x_half;	//Box��X���̔��a
	float box_y_half;	//Box��Y���̔��a

	Color color;
public:
	Shoot();	//�R���X�g���N�^
	~Shoot();	//�f�X�g���N�^

	void SetSpeed(float speed);		//�X�s�[�h�l�̐ݒ�
	void SetBoxColor(Color color_);	//�u���b�N�̐F�̐ݒ�

	void Update();					//�`��ȊO�̍X�V�Ɋւ��鏈��
	void Draw();					//�`��Ɋւ��鏈��
};
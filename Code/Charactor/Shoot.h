#pragma once
#include "Charactor.h"
#include "Player.h"
#include "DxLib.h"
#include "Collision.h"

#define CAMERA_CENTER_X 480
class Shoot :public Charactor
{
private:

	int box_flg;		//Box�\����On�EOff

	float shoot_max_speed;	//�e�̍ō����x
	float shoot_speed;		//�e�̑��x

	float box_x_half;	//Box��X���̔��a
	float box_y_half;	//Box��Y���̔��a

	int shoot_blue;		//�̒e
	int shoot_red;		//�Ԃ̒e
	int shoot_hit_blue;	//�̒e�̃q�b�g�摜
	int shoot_hit_red;	//�Ԃ̒e�̃q�b�g�摜

	int ball_alpha;		//�{�[���̓����x

	int ball_delete;

	Color color;		//�e�̐F�̎���
	Collision* ball_collision;
	Player* player;

public:
	Shoot();	//�R���X�g���N�^
	~Shoot();	//�f�X�g���N�^

	void SetSpeed(float speed);		//�X�s�[�h�l�̐ݒ�

	void SetBoxColor(Color color_);	//�u���b�N�̐F�̐ݒ�
	Color GetShootColor();

	void Update();					//�`��ȊO�̍X�V�Ɋւ��鏈��
	void Draw();					//�`��Ɋւ��鏈��
};
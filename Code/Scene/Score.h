#pragma once
#include"Scene.h"

class Score :public Scene
{
public:
	Score(int now_score);
	void Update()override; //���t���[�����s���鏈���֐��A�����K�{
	void Draw()override; //���t���[�����s����`�ʊ֐�
private:
	int now_score;
	int ranking_score[5];
};


#pragma once
#include"Scene.h"

class Score :public Scene
{
public:
	Score();
	void Update()override; //���t���[�����s���鏈���֐��A�����K�{
	void Draw()override; //���t���[�����s����`�ʊ֐�
private:
	int* score;
	int* high_score;
	int count;
};

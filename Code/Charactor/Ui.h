#pragma once
#include"Charactor.h"

class Ui :public Charactor
{
public:
	Ui();
	~Ui();
	void Update()override; //���t���[�����s���鏈���֐��A�����K�{
	void Draw()override; //���t���[�����s����`�ʊ֐�

private:
	int* score;
	int* high_score;
};


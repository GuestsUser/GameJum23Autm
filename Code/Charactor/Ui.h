#pragma once

class Ui
{
public:
	Ui();
	~Ui();
	void Update(int score); //���t���[�����s���鏈���֐��A�����K�{
	void Draw(); //���t���[�����s����`�ʊ֐�
private:
	int score;
	int high_score;
};


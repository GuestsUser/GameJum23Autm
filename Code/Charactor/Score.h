#pragma once


class Score
{
public:
	Score();
	~Score();
	void Update(); //���t���[�����s���鏈���֐��A�����K�{
	void Draw(); //���t���[�����s����`�ʊ֐�
private:
	int score;
	int high_score;
};

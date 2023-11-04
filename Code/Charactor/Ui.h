#pragma once
#include"Charactor.h"

class Ui :public Charactor
{
public:
	Ui();
	~Ui();
	void Update()override; //毎フレーム実行する処理関数、実装必須
	void Draw()override; //毎フレーム実行する描写関数

	void SetScore(int score) { this->score = score; }

private:
	int score;
	int high_score;
};


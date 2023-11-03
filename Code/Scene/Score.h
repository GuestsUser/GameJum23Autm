#pragma once
#include"Scene.h"

class Score :public Scene
{
public:
	Score(int now_score);
	void Update()override; //毎フレーム実行する処理関数、実装必須
	void Draw()override; //毎フレーム実行する描写関数
private:
	int now_score;
	int ranking_score[5];
};


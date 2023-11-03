#pragma once

class Score
{
public:
	Score();
	void Update(); //毎フレーム実行する処理関数、実装必須
	void Draw(); //毎フレーム実行する描写関数
private:
	int score;
};


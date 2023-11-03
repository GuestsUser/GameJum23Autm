#pragma once

class Ui
{
public:
	Ui();
	~Ui();
	void Update(); //毎フレーム実行する処理関数、実装必須
	void Draw(); //毎フレーム実行する描写関数
private:
	int score;
	int high_score;
};


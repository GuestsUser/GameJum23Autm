#pragma once
#include "Charactor.h"
#include "SimpleAnimation.h"

class GameStart
	:public Charactor
{
public:
	GameStart();
	~GameStart();

	void Update();
	void Draw();

	bool IsShow() { return is_show; }

private:
	int frame_count;
	SimpleAnimation* anim;
	bool is_show;
};



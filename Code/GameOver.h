#pragma once
#include "Charactor.h"
#include "SimpleAnimation.h"

#define IMAGE_ALL_NUM (8)
#define IMAGE_WIDTH (96)
#define IMAGE_HEIGHT (120)

class GameOver
	:public Charactor
{
public:
	GameOver();
	~GameOver();

	void Update();
	void Draw();

	bool IsShow() { return is_show; }

private:
	int frame_count;
	SimpleAnimation* anims[IMAGE_ALL_NUM];
	bool is_show;
	int alpha;
};

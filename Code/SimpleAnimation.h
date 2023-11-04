#pragma once
#include "OriginMath.h"

class SimpleAnimation
{
public:
	SimpleAnimation(int in_image, Vector3 in_pos,
		Vector3 in_target_pos, int moving_frame);
	~SimpleAnimation();

	void Update();
	void Draw();

private:
	int image;
	bool is_moving;
	Vector3 speed;
	Vector3 position;
	Vector3 target_position;

public:
	bool GetIsMoving() { return is_moving; }
};

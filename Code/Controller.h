#pragma once

#include "DxLib.h"

class Controller
{
public:
	Controller() :input_a(true), now(false), old(false) {}
	~Controller() {}

	void Update()
	{
		input_a = (GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A);
		input_a += (CheckHitKey(KEY_INPUT_A));

		old = now;
		now = input_a;
		key = now & ~old;
	}

	static bool OnInputA()
	{
		return key;
	}

private:
	int input_a;
	int now;
	int old;
	static int key;
};

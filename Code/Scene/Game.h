#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"
class ShotGenerator;

class Game :public Scene { //コンパイル用空クラス
public:
	Game();
	~Game();

	void Update()override;
	void Draw()override;

private:
	ShotGenerator* shot_generator;
};
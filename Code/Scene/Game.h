#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"
class ShotGenerator;
class SimpleAnimation;
class GameStart;
class GameOver;

enum class GameState
{
	GameStart
	,Playing
	,PlayerDying
	,GameOver
};

class Game :public Scene { //コンパイル用空クラス
public:
	Game();
	~Game();

	void Update()override;
	void Draw()override;


private:
	GameState state;
	GameStart* game_start;
	GameOver* game_over;
	int wait_count;
	ShotGenerator* shot_generator;

	int stage_image;
	int BGM;
};
#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"
class ShotGenerator;
class SimpleAnimation;
class GameStart;

enum class GameState
{
	GameStart
	,Playing
	,PlayerDying
	,GameOver
};

class Game :public Scene { //�R���p�C���p��N���X
public:
	Game();
	~Game();

	void Update()override;
	void Draw()override;

private:
	GameState state;
	GameStart* game_start;
	int wait_count;
	ShotGenerator* shot_generator;
};
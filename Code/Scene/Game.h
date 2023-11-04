#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"
class ShotGenerator;
class SimpleAnimation;
class GameStart;
class Player;
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
	int wait_count;
	ShotGenerator* shot_generator;
	Player* player;
};
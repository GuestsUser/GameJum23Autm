#include "DxLib.h"
#include "Game.h"
#include "GameStart.h"

#include "ShotGenerator.h"
#include "Player.h"
#include "SimpleAnimation.h"

Game::Game()
	:state(GameState::GameStart)
	,wait_count(0)
{
	shot_generator = CreateObject<ShotGenerator>(Vector3());


	StopUpdateAllObjects();
	game_start = CreateObject<GameStart>(Vector3());
}

Game::~Game()
{

}

void Game::Update()
{
	__super::Update();
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		//	debug mouse input left
	}

	switch (state)
	{
	case GameState::GameStart:
		if (game_start)
		{
			if (game_start->IsShow() == false)
			{
				DestroyObject(game_start);
				state = GameState::Playing;
				BeginUpdateAllObjects();
			}
		}
		break;
	case GameState::Playing:
		break;
	case GameState::PlayerDying:
		break;
	case GameState::GameOver:
		break;
	default:
		break;
	}

}

void Game::Draw()
{
	__super::Draw();
}
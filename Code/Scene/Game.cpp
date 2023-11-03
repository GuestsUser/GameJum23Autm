#include "DxLib.h"
#include "Game.h"

#include "ShotGenerator.h"
#include "Player.h"

Game::Game()
{
	shot_generator = CreateObject<ShotGenerator>(Vector3());
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
}

void Game::Draw()
{
	__super::Draw();
}
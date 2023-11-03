#include "DxLib.h"
#include "Game.h"

Game::Game()
{
	test_chara = CreateObject<Charactor>(Vector3());
}

Game::~Game()
{

}

void Game::Update()
{
	__super::Update();

	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		DestroyAllObjects();
	}
}

void Game::Draw()
{
	__super::Draw();
}
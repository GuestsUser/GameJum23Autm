#include "DxLib.h"
#include "Game.h"

#include "ShotGenerator.h"
#include "Player.h"

Game::Game()
{
	CreateObject<ShotGenerator>(Vector3());
}

Game::~Game()
{

}

void Game::Update()
{
	__super::Update();
}

void Game::Draw()
{
	__super::Draw();
}
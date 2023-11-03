#include"Game.h"

Game::Game() {
	player = new Player();
}

void Game::Update() {
	player->Update();
}

void Game::Draw() {
	player->Draw();
}
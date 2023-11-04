#include "DxLib.h"
#include "Controller.h"
#include "SoundManager/SoundManager.h"

#include "Game.h"
#include "Title.h"

#include "GameStart.h"
#include "GameOver.h"

#include "ShotGenerator.h"
#include "Player.h"
#include "Ui.h"

Game::Game()
	:state(GameState::GameStart)
	,game_start(nullptr)
	,game_over(nullptr)
	,wait_count(0)
	,stage_image (0)
	,BGM(0)
{
	shot_generator = CreateObject<ShotGenerator>(Vector3());
	CreateObject<Ui>(Vector3());
	stage_image = LoadGraph("Resource/image/stage.png");
	BGM = SoundManager::GetBGM("GameMain");
	SoundManager::PlayBGM(BGM);

	StopUpdateAllObjects();
	game_start = CreateObject<GameStart>(Vector3());
	player = CreateObject<Player>(Vector3(300, 400, 0));
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
		if (game_start != nullptr)
		{
			if (game_start->IsShow() == false)
			{
				DestroyObject(game_start);
				game_start = nullptr;
				state = GameState::Playing;
				BeginUpdateAllObjects();
			}
		}
		break;
	case GameState::Playing:
		/*
		* if(Playerが死んだら)
		* {
		*		state = GameState::PlayerDying;
		*		StopUpdateAllObjects();
		*		player->SetIsActive(true)		
		* }
		*/
		break;
	case GameState::PlayerDying:
		/*
		* if(Playerの死亡処理が終わったら)
		* {
		*		state = GameState::GameOver;
		*		StopUpdateAllObjects();
		*		game_over = CreateObject<GameOver>(Vector3());
		* }
		*/
		break;
	case GameState::GameOver:
		if (game_over != nullptr)
		{
			if (game_over->IsShow() == false)
			{
				DestroyObject(game_over);
				game_over = nullptr;
			}
		}
		else
		{	//	game_overが死んでいるならボタンを押してタイトルに戻る
			if (Controller::OnInputA())
			{
				//	debug mouse input left
				SetNext(new Title());
			}
		}
		break;
	default:
		break;
	}

}

void Game::Draw()
{
	DrawGraph(0, 0, stage_image, TRUE);
	__super::Draw();

}
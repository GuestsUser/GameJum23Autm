#pragma once
#include "Scene.h"
#include"Charactor/Player.h"
class Game :public Scene { //�R���p�C���p��N���X
private:
	Player* player;
public:
	Game();

	void Update()override;
	void Draw()override;
};
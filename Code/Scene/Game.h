#pragma once
#include "Scene.h"
#include"Charactor/Player.h"
class Game :public Scene { //コンパイル用空クラス
private:
	Player* player;
public:
	Game();

	void Update()override;
	void Draw()override;
};
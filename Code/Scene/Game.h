#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"
#include "Charactor/Charactor.h"

class Game :public Scene { //�R���p�C���p��N���X
public:
	Game();
	~Game();

	void Update()override;
	void Draw()override;

private:
	Charactor* test_chara;
};
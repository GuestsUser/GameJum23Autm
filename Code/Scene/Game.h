#pragma once
#include "SoundManager/SoundManager.h"
#include "Scene.h"

class Game :public Scene { //�R���p�C���p��N���X
public:
	Game();
	~Game();

	void Update()override;
	void Draw()override;

private:

};
#pragma once
#include"Charactor/Charactor.h"

class Player2:public Charactor {
private :
	
public:
	Player2();
	~Player2();

	void Update();
	void Draw();
	void  HitCheck();
};
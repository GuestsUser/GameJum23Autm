#include"Charactor.h"
#include"Dxlib.h"
#include"Collision.h"
#include"Charactor/Player2.h"

#define JUMP_POWER  10.0f
#define GROUND 400


enum class PlayerState {
	alive,
	deth,
	jump,
};

class Player :public Charactor {
private:
	Collision* collision;
	Collision* collision2;
	Player2* player2;

	PlayerState player_state;
	Color color;

	int player_img[3];
	int player_img2[3];
	
	int frame_count;
	int press;
	
	float jump_power;
	bool jump_flg;
	int score;

public:
	Player();
	~Player();

	void Update()override;
	void Draw()override;
	void ActionCheck();
	void PadDelay(); //コントローラーの連続入力を出来ないようにする
	void Jump();
	void Switch();
	void Anim();
	void CheckPlayerState();
	int GetScore() { return score; }
	void HitCeck();


int GetPlayerState();
};
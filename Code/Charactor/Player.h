#include"Charactor.h"
#include"Dxlib.h"

#define JUMP_POWER  10.0f
#define GROUND 400

enum class PlayerType {
	red,
	blue,
};

enum class PlayerState {
	alive,
	deth,
	jump,
};

class Player :public Charactor {
private:
	Vector3* vector;
	Vector3* vector2;

	PlayerType player_type;
	PlayerState player_state;

	int player_img[3];
	int player_img2[3];
	
	int frame_count;
	int press;
	
	float jump_power;
	bool jump_flg;

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

PlayerType GetPlayerType();
int GetPlayerState();
};
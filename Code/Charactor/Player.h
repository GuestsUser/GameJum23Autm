#include"Charactor.h"
#include"Dxlib.h"

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

	int keep_x, keep_y;

	int fps;
	int press;
	
	float jump_power;
	bool jump_flg;

public:
	Player();
	

	void Update()override;
	void Draw()override;
	void ActionCheck();
	void PadDelay(); //コントローラーの連続入力を出来ないようにする
	void Jump();
	void Switch();

PlayerType HitPlayerType(int type);
PlayerState CheckPlayerState(int state);
};
#include"Player.h"


Player::Player() {
	vector = new Vector3();
	vector2 = new Vector3();

	vector->SetXYZ(300, 400, 0);
	vector2->SetXYZ(500, 400, 0);
	frame_count = 0;
	press = 0;
	jump_power = JUMP_POWER;
	jump_flg = false;
	player_type = PlayerType::red;
	player_state = PlayerState::alive;

	 LoadDivGraph("Resource/image/player1.png",3,3,1,32,48, player_img);
	 LoadDivGraph("Resource/image/player2.png", 3, 3, 1, 32, 48, player_img2);
}

Player::~Player() {
	delete vector, vector2;
	for (int i = 0; i < 3; i++) {
		DeleteGraph(player_img[i]);
		DeleteGraph(player_img2[i]);
	}
}

void Player::Update() {
	PadDelay();
	ActionCheck();
	CheckPlayerState();
	Jump();

}

void Player::Draw() {
	
	DrawGraph(vector->GetX(), vector->GetY(), player_img[GetPlayerState()], TRUE);
	DrawGraph(vector2->GetX(), vector2->GetY(), player_img2[GetPlayerState()], TRUE);
	
}

void Player::Jump() {
	

	if (jump_flg == true) {
		vector->SetY(vector->GetY() - jump_power);
		vector2->SetY(vector->GetY());
		jump_power -= 0.5f;
	}
	if (vector->GetY() > GROUND) {
		jump_flg = false;
		jump_power = JUMP_POWER;
		vector->SetY(GROUND);
		vector2->SetY(GROUND);
	}

}

void Player::PadDelay() {
	if (frame_count >= 30) {
		frame_count = 0;
	}
	else {
		frame_count++;
	}
}

void Player::ActionCheck() {
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) == 0 && frame_count <= 30) {
		if (press <= 10 && press > 0)jump_flg = true;
		else if (press > 10)Switch();                                          //ˆÊ’uŒðŠ·‚Ìˆ—‚ð’Ç‰Á‚·‚é
		press = 0;
	}
	else {//‰Ÿ‚³‚ê‚Ä‚éŠÔ‚Ìˆ—
		press++;
	}
	
}

void Player::Switch() {
	float keep_x, keep_y;

	keep_x = vector->GetX();
	keep_y = vector->GetY();
	vector->SetX(vector2->GetX());
	vector->SetY(vector2->GetY());
	vector2->SetX(keep_x);
	vector2->SetY(keep_y);
}

PlayerType  Player::GetPlayerType() {
	return player_type;
}

int Player::GetPlayerState() {
	if (player_state == PlayerState::alive)return 0;
	if (player_state == PlayerState::deth)return 1;
	if (player_state == PlayerState::jump)return 2;
}

void Player::Anim() {

}

void Player::CheckPlayerState() {
	if (jump_flg == true)player_state = PlayerState::jump;
	if (jump_flg == false)player_state = PlayerState::alive;
}
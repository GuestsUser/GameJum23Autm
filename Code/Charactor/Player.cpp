#include"Player.h"


Player::Player() {
	vector = new Vector3();
	vector2 = new Vector3();

	vector->SetXYZ(300, 400, 0);
	vector2->SetXYZ(500, 400, 0);
	keep_x = 0;
	keep_y = 0;
	fps = 0;
	press = 0;
	jump_power = 20.0f;
	jump_flg = false;
	player_type = PlayerType::red;
	player_state = PlayerState::alive;
}

void Player::Update() {
	PadDelay();
	ActionCheck();
	
	Jump();

}

void Player::Draw() {
	DrawBox(vector->GetX(), vector->GetY(), vector->GetX() + 64, vector->GetY() + 96, 0xFFFFFF, TRUE);
	DrawBox(vector2->GetX(), vector2->GetY(), vector2->GetX() + 64, vector2->GetY() + 96, 0xFFFFF, TRUE);
}

void Player::Jump() {
	

	if (jump_flg == true) {
		vector->SetY(vector->GetY() - jump_power);
		vector2->SetY(vector->GetY());
		jump_power -= 0.5f;
	}
	if (vector->GetY() > 400) {
		jump_flg = false;
		jump_power = 20.0f;
		vector->SetY(400);
		vector2->SetY(400);
	}

}

void Player::PadDelay() {
	if (fps >= 30) {
		fps = 0;
	}
	else {
		fps++;
	}
}

void Player::ActionCheck() {
	if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_A) == 0 && fps <= 30) {
		if (press <= 10 && press > 0)jump_flg = true;
		else if (press > 10)Switch();                                          //�ʒu�����̏�����ǉ�����
		press = 0;
	}
	else {//������Ă�Ԃ̏���
		press++;
	}
	
}

void Player::Switch() {
	keep_x = vector->GetX();
	keep_y = vector->GetY();
	vector->SetX(vector2->GetX());
	vector->SetY(vector2->GetY());
	vector2->SetX(keep_x);
	vector2->SetY(keep_y);
}

PlayerType  Player::HitPlayerType(int type) {
	if (type == 0)return player_type = PlayerType::red;
	if (type == 1)return player_type = PlayerType::blue;
}

PlayerState Player::CheckPlayerState(int state) {
	if (state == 0)return player_state = PlayerState::alive;
	if (state == 1)return player_state = PlayerState::deth;
}
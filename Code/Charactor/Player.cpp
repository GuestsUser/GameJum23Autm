#include"Player.h"
#include "Shoot.h"
#include"../Worldval.h"


Player::Player() {
	this->EditPosition().SetXYZ(500, 400, 0);
	player2 = new Player2();
	player2->EditPosition().SetXYZ(540, 400, 0);

	collision = new Collision(this, Vector3(16, 24, 0), Vector3(16, 24, 0));
	collision2 = new Collision(player2, Vector3(16, 24, 0), Vector3(16, 24, 0));

	player_color = Color::BLUE;
	player2_color = Color::RED;

	score=WorldVal::Get<int>("score");//スコアを取得;
	*score = 0;

	frame_count = 0;
	press = 0;
	jump_power = JUMP_POWER;
	jump_flg = false;
	deth_flg = false;
	hit = false;
	player_state = PlayerState::alive;
	
	 LoadDivGraph("Resource/image/player1.png",3,3,1,32,48, player_img);
	 LoadDivGraph("Resource/image/player2.png", 3, 3, 1, 32, 48, player_img2);
}

Player::~Player() {
	delete collision, collision2;
	delete player2;
	for (int i = 0; i < 3; i++) {
		DeleteGraph(player_img[i]);
		DeleteGraph(player_img2[i]);
	}
}

void Player::Update() {
	
	PadDelay();
	ActionCheck();
	HitCheck();
	CheckPlayerState();
	Jump();
	
}

void Player::Draw() {
	
	DrawGraph(this->EditPosition().GetX(), this->EditPosition().GetY(), player_img[GetPlayerState()], TRUE);
	DrawGraph(player2->EditPosition().GetX(), player2->EditPosition().GetY(), player_img2[GetPlayerState()], TRUE);
	
}

void Player::Jump() {
	

	if (jump_flg == true) {
		this->EditPosition().SetY((this->EditPosition().GetY() - jump_power));
		player2->EditPosition().SetY(this->EditPosition().GetY());
		jump_power -= 0.5f;
	}
	if (this->EditPosition().GetY() > GROUND) {
		jump_flg = false;
		jump_power = JUMP_POWER;
		this->EditPosition().SetY(GROUND);
		player2->EditPosition().SetY(GROUND);
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
		if (press <= 5 && press > 0)jump_flg = true;
		else if (press > 5)Switch();                                          //位置交換の処理を追加する
		press = 0;
	}
	else {//押されてる間の処理
		press++;
	}
	
}

void Player::Switch() {
	float keep_x, keep_y;

	keep_x = this->EditPosition().GetX();
	keep_y = this->EditPosition().GetY();
	this->EditPosition().SetX(player2->EditPosition().GetX());
	this->EditPosition().SetY(player2->EditPosition().GetY());
	player2->EditPosition().SetX(keep_x);
	player2->EditPosition().SetY(keep_y);
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
	if (deth_flg == true)player_state = PlayerState::deth;
}

void Player::HitCheck() {
	Shoot* shoot = dynamic_cast<Shoot*>(collision->HitCheck());
	Shoot* shoot2 = dynamic_cast<Shoot*>(collision2->HitCheck());
	if (shoot != nullptr) {
		Color hit_color = shoot->GetShootColor();
		if (player_color == hit_color) {
			hit = true;
			*score += 1;

		}
		else {
			hit = true;
			deth_flg = true;
		}
			
	}
	if (shoot2 != nullptr) {
		Color hit_color = shoot2->GetShootColor();
		if (player2_color == hit_color) {
			hit = true;
			*score += 1;
		}
		else {
			hit = true;
			deth_flg = true;
		}

	}
	if (shoot == nullptr)hit = false;
}

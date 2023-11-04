#include"Player.h"



Player::Player() {
	
	collision = new Collision(this, Vector3(32), Vector3(16));

	this->EditPosition().SetXYZ(300, 400, 0);
	player2 = new Player2();
	player2->EditPosition().SetXYZ(500, 400, 0);


	frame_count = 0;
	press = 0;
	jump_power = JUMP_POWER;
	jump_flg = false;
	player_state = PlayerState::alive;
	score = 0;

	 LoadDivGraph("Resource/image/player1.png",3,3,1,32,48, player_img);
	 LoadDivGraph("Resource/image/player2.png", 3, 3, 1, 32, 48, player_img2);
}

Player::~Player() {
	delete this, player2;
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

	//if(“–‚½‚Á‚½‚È‚ç)get_point = TRUE;
	//else get_point = FALSE;

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
	
}
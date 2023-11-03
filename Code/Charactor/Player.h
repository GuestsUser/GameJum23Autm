#include"Charactor.h"
#include"Dxlib.h"

class Player :public Charactor {
private:
	Vector3* vector;
	Vector3* vector2;

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
	void PadDelay(); //�R���g���[���[�̘A�����͂��o���Ȃ��悤�ɂ���
	void Jump();
	void Switch();
};
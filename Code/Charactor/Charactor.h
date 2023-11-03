#pragma once
#include "OriginMath.h"
#include "Object.h"

class Charactor	:public Object { //ゲーム内に登場する最低限のキャラクター、各種キャラはこれを継承して登場させてほしい
	Vector3 pos;
public:
	Charactor() :pos(Vector3()) {}
	virtual ~Charactor() {}

	virtual void Update() override{}
	virtual void Draw() override{}

	const Vector3& ReadPosition() const { return pos; } //読み出し専用でポジションの取得
	Vector3& EditPosition() { return pos; } //編集可能な形式でポジションの取得
};
#pragma once
#include "OriginMath.h"

enum class Color
{
	RED,	//( 0 )
	BLUE	//( 1 )
};

class Charactor { //ゲーム内に登場する最低限のキャラクター、各種キャラはこれを継承して登場させてほしい
	Vector3 pos;
public:
	Charactor() :pos(Vector3()) {}
	virtual ~Charactor() {}

	virtual void Update() {}
	virtual void Draw() {}

	const Vector3& ReadPosition() const { return pos; } //読み出し専用でポジションの取得
	Vector3& EditPosition() { return pos; } //編集可能な形式でポジションの取得
};
#pragma once
#include "OriginMath.h"
#include "DxLib.h"

enum class Color
{
	RED,	//( 0 )
	BLUE	//( 1 )
};

class Charactor { //ゲーム内に登場する最低限のキャラクター、各種キャラはこれを継承して登場させてほしい
	int draw_priority;
	Vector3 pos;
public:
	Charactor(int in_draw_priority = 99) :pos(Vector3()), draw_priority(in_draw_priority) {}
	virtual ~Charactor() {}

	virtual void Update() {}
	virtual void Draw() {}

	const Vector3& ReadPosition() const { return pos; } //読み出し専用でポジションの取得
	Vector3& EditPosition() { return pos; } //編集可能な形式でポジションの取得

	//	描画優先度の公開(低いほうから順に描画 背景は0)
	void SetDrawPriority(int in_draw_priority) { draw_priority = in_draw_priority; }
	int GetDrawPriority() { return draw_priority; }
};
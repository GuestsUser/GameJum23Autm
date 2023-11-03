#pragma once
#include "OriginMath.h"
#include <deque>


class Charactor;

class Collision {
	static std::deque<Collision*> list; //シーン全てのコリジョンを保持する

	Charactor* parent; //このコリジョンを保持するキャラクター参照を持つ
	Vector3 size; //コリジョンサイズ、半径サイズを想定、つまり実際の占有幅は-size～sizeまで
	Vector3 relativePos; //parentのポジションを起点にどれ位離れているかを記録
public:
	Collision(Charactor* parent, Vector3 size = Vector3(1, 1, 1), Vector3 relativePos = Vector3());
	~Collision();

	Charactor* HitCheck(); //ヒットチェックを行う、ヒットがあった場合ヒットしたCharactorを返す
};
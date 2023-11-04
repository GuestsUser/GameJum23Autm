#include "Collision.h"
#include "Charactor.h"

std::deque<Collision*> Collision::list= std::deque<Collision*>();

Collision::Collision(Charactor* parent, Vector3 size, Vector3 relativePos):parent(parent), size(size), relativePos(relativePos) {
	list.push_back(this); //自身をリストに追加
}

Collision::~Collision() {
	for (int i = 0; i < list.size(); ++i) {
		if (this == list[i]) { list.erase(list.begin() + i); } //自身をリストから除外
	}
}

Charactor* Collision::HitCheck() {
	Vector3 worldPos = parent->ReadPosition() + relativePos; //relativePosを反映したコリジョン位置
	for (auto itr : list) {
		Vector3 targetPos= itr->parent->ReadPosition() + itr->relativePos; //判定対象のrelativePos反映版

		if (itr == this) { continue; } //自分自身を判定対象外に

		if (worldPos.GetX() + size.GetX() <= targetPos.GetX() - itr->size.GetX()) { continue; } //其々のコリジョンの重なりがない場合continue
		if (worldPos.GetX() - size.GetX() >= targetPos.GetX() + itr->size.GetX()) { continue; }
		if (worldPos.GetY() + size.GetY() <= targetPos.GetY() - itr->size.GetY()) { continue; }
		if (worldPos.GetY() - size.GetY() >= targetPos.GetY() + itr->size.GetY()) { continue; }

		return itr->parent; //ここまで来れればこのキャラクターがヒットしている
	}
	return nullptr; //for文でヒットがなかった場合null
}

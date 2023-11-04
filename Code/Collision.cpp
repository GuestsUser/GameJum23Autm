#include "Collision.h"
#include "Charactor.h"

std::deque<Collision*> Collision::list= std::deque<Collision*>();

Collision::Collision(Charactor* parent, Vector3 size, Vector3 relativePos):parent(parent), size(size), relativePos(relativePos) {
	list.push_back(this); //���g�����X�g�ɒǉ�
}

Collision::~Collision() {
	for (int i = 0; i < list.size(); ++i) {
		if (this == list[i]) { list.erase(list.begin() + i); } //���g�����X�g���珜�O
	}
}

Charactor* Collision::HitCheck() {
	Vector3 worldPos = parent->ReadPosition() + relativePos; //relativePos�𔽉f�����R���W�����ʒu
	for (auto itr : list) {
		Vector3 targetPos= itr->parent->ReadPosition() + itr->relativePos; //����Ώۂ�relativePos���f��

		if (itr == this) { continue; } //�������g�𔻒�ΏۊO��

		if (worldPos.GetX() + size.GetX() <= targetPos.GetX() - itr->size.GetX()) { continue; } //���X�̃R���W�����̏d�Ȃ肪�Ȃ��ꍇcontinue
		if (worldPos.GetX() - size.GetX() >= targetPos.GetX() + itr->size.GetX()) { continue; }
		if (worldPos.GetY() + size.GetY() <= targetPos.GetY() - itr->size.GetY()) { continue; }
		if (worldPos.GetY() - size.GetY() >= targetPos.GetY() + itr->size.GetY()) { continue; }

		return itr->parent; //�����܂ŗ����΂��̃L�����N�^�[���q�b�g���Ă���
	}
	return nullptr; //for���Ńq�b�g���Ȃ������ꍇnull
}

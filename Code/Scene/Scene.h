#pragma once
#include "Charactor/Charactor.h"
#include <vector>

class Scene { //���̃N���X���p�����ăV�[��������Update�ɁA�`�ʏ�����Draw�ɒ�`����
public:
	Scene() :next(this) {} //���������Ɏ��g�����Ă���
	virtual ~Scene(); //�p���\�ȃN���X�̓f�X�g���N�^�ɉ��z�֐��w�肪�Ȃ��Ɛe�N���X�̃f�X�g���N�^�����Ăяo����Ȃ��̂�virtual�w������Ă���
	
	virtual void Update(); //���t���[�����s���鏈���֐�
	virtual void Draw();   //���t���[�����s����`�ʊ֐�
	virtual void FullReset() {} //���S���Z�b�g���������̊֐�
	virtual void Reset() {} //�V�����Q�[�����̗��R�ŃV�[�����Z�b�g�������Ȃ������̊֐�

	bool SetNext(Scene* set){ //�V�[���`�F���W�p�A�����Ɏ��V�[���̎��̂�����
		//if (next != this) { return false; } //���Ɏ��V�[���̎w�肪�Ȃ���Ă���ꍇ���s
		next = set; //���V�[����ݒ�
		return true; //������Ԃ�
	}
	Scene* GetNext() { return next; } //���V�[���̎擾

	template <class T>
	T* CreateObject(const Vector3& position)
	{
		//	GameObject�̐���
		T* new_instance = new T();
		Charactor* new_object = dynamic_cast<Charactor*>(new_instance);

		//	Charactor��h�����Ă��Ȃ��ꍇ�Ǘ��ł��Ȃ��̂Ŕj������
		if (new_object == nullptr)
		{
			delete new_instance;
			return nullptr;
		}

		//	GameObject�̓o�^
		scene_objects.push_back(new_object);


		//	�ʒu�ݒ�
		new_object->EditPosition() = position;

		return new_instance;

	}

	void DestroyObject(Charactor* object);

	void DestroyAllObjects();

private:
	Scene* next; //�V�[���J�ڂ���ꍇ���V�[�����́A���̂܂܂̏ꍇ���g�A�E�B���h�E�����ꍇnullptr������
	std::vector<Charactor*> scene_objects;
};
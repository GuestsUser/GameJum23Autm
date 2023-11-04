#include "SceneManager.h"
#include "./Scene/Scene.h"
#include "SceneAccessor.h"
#include "Controller.h"

SceneManager::SceneManager(Scene* ini)
	:run(ini)
{
	SceneAccessor::Initialize(ini);
	accessor_insctance = SceneAccessor::GetInstance();
	controller = new Controller();
}

SceneManager::~SceneManager()
{
	delete controller;
}

bool SceneManager::Update() {
	//while (true) { //�ڍs��̃V�[������x��update���Ăяo���׃��[�v�d�l
	//	run->Update(); //update���s
	//	Scene* next = run->GetNext(); //���V�[���̎擾
	//	if (run == next) { break; } //�p���������烋�[�v����

	//	delete run; //�ڍs�𖽗߂��ꂽ�猻�݃V�[���̍폜
	//	if (next == nullptr) { run = nullptr; return false; } //�I������
	//	run = next; //���s����V�[��������̕��ɍX�V
	//}
	while (true) { //�ڍs��̃V�[����update�̌Ăяo�����s��Ȃ��d�l
		run->Update(); //update���s
		Scene* next = run->GetNext(); //���V�[���̎擾
		controller->Update();
		if (run == next) { break; } //�p���������烋�[�v����

		delete run; //�ڍs�𖽗߂��ꂽ�猻�݃V�[���̍폜
		accessor_insctance->SetCurrentScene(next);	//	�A�N�Z�T�̃V�[�����X�V
		run = next; //���s����V�[��������̕��ɍX�V
		run->SortBasedOnPriority();//	����̃V�[���̕`�揇�𐮂���
		if (run == nullptr) { return false; } //����̕��ɉ��������ĂȂ������ꍇ�E�B���h�E����閽�߂�ʒm����
	}
	return true; //Draw�ɏ������ڂ�
}

void SceneManager::Draw() { run->Draw(); }
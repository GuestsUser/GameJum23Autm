#pragma once
#include <map>
#include <string>

using namespace std;

struct Sound
{
	int handle;		//�������Ɋm�ۂ����n���h��
	bool isDone = false;	//�Ō�܂ōĐ����ꂽ��
};

class SoundManager
{
private:
	SoundManager();					//�R���X�g���N�^
	static SoundManager* instance;	//�C���X�^���X
public:
	~SoundManager();
	//�V���O���g��
	static SoundManager* GetInstance();//�C���X�^���X�̎擾
	static void DeleteThis();		//�����̍폜

private:
	map<string, Sound>bgm;			//BGM�p�z��
	map<string, Sound>se;			//SE�p�z��

public:
	static int GetBGM(const char*);		//BGM�n���h���̎擾
	static int GetSE(const char*);		//SE�n���h���̎擾
	static void PlayBGM(int handle);	//BGM�̍Đ�
	static void PlaySE(int handle, bool isSingle = true);		//SE�̍Đ�
};

//	�g����
/*****************************************
* constructor
* {
*	handle(int) = SoundManager::GetSE("se");
*		"se"�͊g���q�����̃t�@�C�����ł��B
*		sample.mp3�Ȃ�	"sample"���w�肵�܂��B
* }
* 
* �Đ�����Ƃ�
* SoundManager::PlaySE(handle);
* Get�Ŏ擾�����n���h�������̂܂܂�����OK�ł�
* �f�t�H���g�ł͖��t���[���Ă΂�Ă��Đ����I���܂ł�2��ڈȍ~���������悤�ɂȂ��Ă��܂��B
* �A���Ŗ炵�����Ƃ��A�����炵�����Ƃ��� isSingle�̈�����false���w�肵�Ă�������
******************************************/
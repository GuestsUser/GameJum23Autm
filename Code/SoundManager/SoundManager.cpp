#include "DxLib.h"
#include "SoundManager.h"

SoundManager* SoundManager::instance = nullptr;

SoundManager::SoundManager()
{
	
}

SoundManager::~SoundManager()
{
	
}

/*
* �C���X�^���X�̎擾
*/
SoundManager* SoundManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new SoundManager();
	}
	return instance;
}

/*
* �������g�̍폜
*/
void SoundManager::DeleteThis()
{
	delete instance;
	instance = nullptr;
}

/*
* BGM�n���h���̎擾
* ����Ȃ炻�̃n���h����Ԃ�
* �Ȃ��Ȃ�Load���ăn���h����Ԃ�
*/
int SoundManager::GetBGM(const char* bgm_name)
{
	//�C���X�^���X���m�ۂ���Ă��Ȃ����NULL��Ԃ�
	if (instance == nullptr)
	{
		return NULL;
	}

	string soundName = string(bgm_name);
	map<string, Sound>::iterator it;

	//����������O��BGM��Load����Ă��邩
	it = instance->bgm.find(soundName);
	if (it != instance->bgm.end())		//����Ă���ꍇ
	{
		//�n���h����Ԃ�
		return instance->bgm[soundName].handle;
	}
	else								//����Ă��Ȃ��ꍇ
	{
		//�p�X���쐬�ABGM�����[�h���ĕԂ�
		string path;
		path = "resource/BGM/" + soundName + ".wav";
		return instance->bgm[soundName].handle = LoadSoundMem(path.c_str());
	}
}

/*
* SE�n���h���̎擾
* ����Ȃ炻�̃n���h����Ԃ�
* �Ȃ��Ȃ�Load���ăn���h����Ԃ�
*/
int SoundManager::GetSE(const char* se_name)
{
	SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);

	//�C���X�^���X���m�ۂ���Ă��Ȃ����NULL��Ԃ�
	if (instance == nullptr)
	{
		return NULL;
	}
	string soundName = string(se_name);
	map<string, Sound>::iterator it;

	//����������O��SE��Load����Ă��邩
	it = instance->se.find(soundName);
	if (it != instance->se.end())		//����Ă���ꍇ
	{
		//�n���h����Ԃ�
		return instance->se[soundName].handle;
	}
	else								//����Ă��Ȃ��ꍇ
	{
		//�p�X���쐬�ASE�����[�h���ĕԂ�
		string path;
		path = "resource/SE/" + soundName + ".mp3";
		return instance->se[soundName].handle = LoadSoundMem(path.c_str(),8);
	}

	SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	return NULL;
}

/*
* BGM�̍Đ�
* int handle BGM�̃n���h�� GetBGM����擾�\
*/
void SoundManager::PlayBGM(int handle)
{
	//�C���X�^���X���m�ۂ���Ă��Ȃ���Ή������Ȃ�
	if (instance == nullptr)
	{
		return;
	}

	//Load����Ă���BGM�𑖍�����
	for (pair<string, Sound> sound : instance->bgm)
	{
		if (CheckSoundMem(sound.second.handle))			//�Ώۂ�BGM���Đ�����
		{
			if (sound.second.handle != handle)			//�Đ�������BGM�ł͂Ȃ��Ȃ�~�߂�
			{
				StopSoundMem(sound.second.handle);
			}
		}
		else
		{
			if (sound.second.handle == handle)			//�Đ�������BGM���Đ�����ĂȂ��Ȃ�Đ�����
			{
				PlaySoundMem(handle,DX_PLAYTYPE_LOOP);
			}
		}

	}
}

/*
* SE�̍Đ�
* int handle SE�̃n���h�� GetSE����擾�\
* bool isSingle �P���Đ��ɂ��邩�ǂ���
* �Đ����ɂ����������d�˂čĐ�����ꍇ�� isSingle ��false�ɂ���
*/
void SoundManager::PlaySE(int handle, bool isSingle)
{
	if (isSingle)
	{
		if (CheckSoundMem(handle) == FALSE)
		{
			PlaySoundMem(handle, DX_PLAYTYPE_BACK);
		}
	}
	else
	{
		PlaySoundMem(handle,DX_PLAYTYPE_BACK);
	}
}
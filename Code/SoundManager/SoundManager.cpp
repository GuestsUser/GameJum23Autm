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
* インスタンスの取得
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
* 自分自身の削除
*/
void SoundManager::DeleteThis()
{
	InitSoundMem();
	delete instance;
	instance = nullptr;
}

/*
* BGMハンドルの取得
* あるならそのハンドルを返す
* ないならLoadしてハンドルを返す
*/
int SoundManager::GetBGM(const char* bgm_name)
{
	//インスタンスが確保されていなければNULLを返す
	if (instance == nullptr)
	{
		return NULL;
	}

	string soundName = string(bgm_name);
	map<string, Sound>::iterator it;

	//もらった名前のBGMがLoadされているか
	it = instance->bgm.find(soundName);
	if (it != instance->bgm.end())		//されている場合
	{
		//ハンドルを返す
		return instance->bgm[soundName].handle;
	}
	else								//されていない場合
	{
		//パスを作成、BGMをロードして返す
		string path;
		path = "resource/BGM/" + soundName + ".mp3";
		return instance->bgm[soundName].handle = LoadSoundMem(path.c_str());
	}
}

/*
* SEハンドルの取得
* あるならそのハンドルを返す
* ないならLoadしてハンドルを返す
*/
int SoundManager::GetSE(const char* se_name)
{
	SetCreateSoundDataType(DX_SOUNDDATATYPE_MEMNOPRESS);

	//インスタンスが確保されていなければNULLを返す
	if (instance == nullptr)
	{
		return NULL;
	}
	string soundName = string(se_name);
	map<string, Sound>::iterator it;

	//もらった名前のSEがLoadされているか
	it = instance->se.find(soundName);
	if (it != instance->se.end())		//されている場合
	{
		//ハンドルを返す
		return instance->se[soundName].handle;
	}
	else								//されていない場合
	{
		//パスを作成、SEをロードして返す
		string path;
		path = "resource/SE/" + soundName + ".mp3";
		return instance->se[soundName].handle = LoadSoundMem(path.c_str(),8);
	}

	SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	return NULL;
}

/*
* BGMの再生
* int handle BGMのハンドル GetBGMから取得可能
*/
void SoundManager::PlayBGM(int handle)
{
	//インスタンスが確保されていなければ何もしない
	if (instance == nullptr)
	{
		return;
	}

	//LoadされているBGMを走査する
	for (pair<string, Sound> sound : instance->bgm)
	{
		if (CheckSoundMem(sound.second.handle))			//対象のBGMが再生中か
		{
			if (sound.second.handle != handle)			//再生したいBGMではないなら止める
			{
				StopSoundMem(sound.second.handle);
			}
		}
		else
		{
			if (sound.second.handle == handle)			//再生したいBGMが再生されてないなら再生する
			{
				PlaySoundMem(handle,DX_PLAYTYPE_LOOP);
			}
		}

	}
}

/*
* SEの再生
* int handle SEのハンドル GetSEから取得可能
* bool isSingle 単発再生にするかどうか
* 再生中にも同じ音を重ねて再生する場合は isSingle をfalseにする
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
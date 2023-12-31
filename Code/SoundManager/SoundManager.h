#pragma once
#include <map>
#include <string>

using namespace std;

struct Sound
{
	int handle;		//メモリに確保したハンドル
	bool isDone = false;	//最後まで再生されたか
};

class SoundManager
{
private:
	SoundManager();					//コンストラクタ
	static SoundManager* instance;	//インスタンス
public:
	~SoundManager();
	//シングルトン
	static SoundManager* GetInstance();//インスタンスの取得
	static void DeleteThis();		//自分の削除

private:
	map<string, Sound>bgm;			//BGM用配列
	map<string, Sound>se;			//SE用配列

public:
	static int GetBGM(const char*);		//BGMハンドルの取得
	static int GetSE(const char*);		//SEハンドルの取得
	static void PlayBGM(int handle);	//BGMの再生
	static void PlaySE(int handle, bool isSingle = true);		//SEの再生
};

//	使い方
/*****************************************
* constructor
* {
*	handle(int) = SoundManager::GetSE("se");
*		"se"は拡張子無しのファイル名です。
*		sample.mp3なら	"sample"を指定します。
* }
* 
* 再生するとき
* SoundManager::PlaySE(handle);
* Getで取得したハンドルをそのままいれればOKです
* デフォルトでは毎フレーム呼ばれても再生が終わるまでは2回目以降無視されるようになっています。
* 連続で鳴らしたいとき、複数鳴らしたいときは isSingleの引数にfalseを指定してください
******************************************/
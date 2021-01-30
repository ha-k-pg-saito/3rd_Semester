#ifndef InputManager_h_
#define InputManager_h_
#include"../Scene/KeyDefinition.h"

//入力管理クラス
class InputManager
{

private:
	struct KeyState
	{
		bool old;		//前回チェック時のフラグ情報

		bool push;		//押された瞬間
		bool on;		//押下されている
		bool pull;		//離された瞬間

		KeyState()
			:old(false)
			, push(false)
			, on(false)
			, pull(false)
		{}
	};

public:
	//キー入力更新
	void Update();
	
	//キーが押されたか
	bool IsPush(KeyType key) const;
	bool IsOn(KeyType key) const;
	bool IsPull(KeyType key) const;

private:
	KeyState m_State[KeyType_Max];


//------------------------------------------------------
//	シングルトンデザイン
public:
	//実体を作る関数
	static void CreateInstance();
	//実体を破棄する関数
	static void DestroyInstance();
	//実体があるかどうか確認する関数
	static bool IsNull();
	//実体を取得する関数
	static InputManager* GetInstance();

private:
	InputManager();
	~InputManager();

private:
	static InputManager* m_pInstance;

};



#endif


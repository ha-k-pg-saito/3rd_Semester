#ifndef GameManager_h_
#define GameManager_h_

//ゲーム全体の管理クラス
class GameManager
{
//------------------------------------------------------
		//	シングルトンデザイン
public:
	//staticなm_pInstanceへのアクセス用関数群
	//実体を作る関数
	static void CreateInstance();
	//実体を破棄する関数
	static void DestroyInstance();
	//実体があるかどうか確認する関数
	static bool IsNull();
	//実体を取得する関数
	static GameManager* GetInstance();

private:
	//好き勝手作られないように、コンストラクタ、デストラクタをpravateメンバーにする
	GameManager();
	~GameManager();

private:
		//staticにすることで、クラスで１つだけであることを保証する	
	static GameManager* m_pInstance;	//自分自身の唯一の実体
};

#endif

#ifndef Manager_h_
#define Manager_h_

#include"../Definition.h"

//シーン管理クラス
class SceneManager
{
public:
	

	void Exec();	//シーンを実行
	void Draw();	//シーンの描画

	static void SetNextScene(SceneID next_);	//次のシーン設定

private:
	class SceneBase* create_NextScene();		//次のシーン作成

private:
	class SceneBase*	m_Scene;		//実行中のシーン
	static SceneID		m_NextSceneID;	//次に作るシーンのID

//------------------------------------------------------
//	シングルトンデザイン
	
public:
	//staaticなm_pInstanceへのアクセス用関数群
	//実体を作る関数
	static void CreateInstance();
	//実体を破棄する関数
	static void DestroyInstance();
	//実体があるかどうか確認する関数
	static bool IsNull();
	//実体を取得する関数
	static SceneManager* GetInstance();


private:
	SceneManager();
	~SceneManager();
	
private:
	static SceneManager* m_pInstance;

};

#endif

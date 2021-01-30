#include"Manager.h"
#include"../Scene/Scene.h"
#include"../Scene/Title.h"
#include"../Scene/InGame.h"
#include"../Scene/Result.h"

//staticなメンバ変数を初期化
SceneID SceneManager::m_NextSceneID = SceneID_Invalid;


void SceneManager::Exec()
{
	if (m_Scene == nullptr)
	{
		return;
	}
	m_Scene->Exec();
	if (m_Scene->IsEnd())
	{
		delete m_Scene;
		m_Scene = create_NextScene();
	}
}

void SceneManager::Draw()
{
	if (m_Scene == nullptr)
	{
		return;
	}
	m_Scene->Draw();
}

void SceneManager::SetNextScene(SceneID next_)
{
	m_NextSceneID = next_;

}

SceneBase* SceneManager::create_NextScene()
{
	SceneBase* next = nullptr;
	switch (m_NextSceneID)
	{
	case SceneID_Title:  
		next=new TitleScene();  
		break;
	case SceneID_InGame: 
		next=new InGameScene(); 
		break;
	case SceneID_Result: 
		next=new ResultScene(); 
		break;
	default:                                
		break;
	}
	return next;
}

//------------------------------------------------------
		//	シングルトンデザイン
SceneManager* SceneManager::m_pInstance = nullptr;
//実体を作る関数

void SceneManager::CreateInstance()
{
	//nullチェックをして、2回以上作られるのを防止
	if (m_pInstance == nullptr)
	{
		m_pInstance = new SceneManager();
	}
}

//実体を破棄する関数
void SceneManager::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}

//実体があるかどうか確認する関数
bool SceneManager::IsNull()
{
	return (m_pInstance == nullptr);
}

//実体を取得する関数
SceneManager* SceneManager::GetInstance()
{
	return m_pInstance;
}

SceneManager::SceneManager()
	:m_Scene(nullptr)
{
	//最初に実行するシーンを作成
	SetNextScene(SceneID_Title);
	m_Scene = create_NextScene();

}

SceneManager::~SceneManager()
{
	delete m_Scene;
	m_Scene = nullptr;
}

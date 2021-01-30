#include"Manager.h"
#include"../Scene/Scene.h"
#include"../Scene/Title.h"
#include"../Scene/InGame.h"
#include"../Scene/Result.h"

//static�ȃ����o�ϐ���������
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
		//	�V���O���g���f�U�C��
SceneManager* SceneManager::m_pInstance = nullptr;
//���̂����֐�

void SceneManager::CreateInstance()
{
	//null�`�F�b�N�����āA2��ȏ�����̂�h�~
	if (m_pInstance == nullptr)
	{
		m_pInstance = new SceneManager();
	}
}

//���̂�j������֐�
void SceneManager::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}

//���̂����邩�ǂ����m�F����֐�
bool SceneManager::IsNull()
{
	return (m_pInstance == nullptr);
}

//���̂��擾����֐�
SceneManager* SceneManager::GetInstance()
{
	return m_pInstance;
}

SceneManager::SceneManager()
	:m_Scene(nullptr)
{
	//�ŏ��Ɏ��s����V�[�����쐬
	SetNextScene(SceneID_Title);
	m_Scene = create_NextScene();

}

SceneManager::~SceneManager()
{
	delete m_Scene;
	m_Scene = nullptr;
}

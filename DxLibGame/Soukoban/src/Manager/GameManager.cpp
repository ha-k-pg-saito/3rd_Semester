#include"../Manager/GameManager.h"

//------------------------------------------------------
		//	�V���O���g���f�U�C��
GameManager* GameManager::m_pInstance=nullptr;
	//���̂����֐�

void GameManager::CreateInstance()
{
	//null�`�F�b�N�����āA2��ȏ�����̂�h�~
	if (m_pInstance==nullptr)
	{
		m_pInstance = new GameManager();
	}
}

//���̂�j������֐�
void GameManager::DestroyInstance()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}

//���̂����邩�ǂ����m�F����֐�
bool GameManager::IsNull()
{
	return (m_pInstance == nullptr);
}

//���̂��擾����֐�
GameManager* GameManager::GetInstance()
{
	return m_pInstance;
}		

GameManager::GameManager()
{
}

GameManager::~GameManager()
{

}
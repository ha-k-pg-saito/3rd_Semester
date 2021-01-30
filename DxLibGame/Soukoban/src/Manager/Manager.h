#ifndef Manager_h_
#define Manager_h_

#include"../Definition.h"

//�V�[���Ǘ��N���X
class SceneManager
{
public:
	

	void Exec();	//�V�[�������s
	void Draw();	//�V�[���̕`��

	static void SetNextScene(SceneID next_);	//���̃V�[���ݒ�

private:
	class SceneBase* create_NextScene();		//���̃V�[���쐬

private:
	class SceneBase*	m_Scene;		//���s���̃V�[��
	static SceneID		m_NextSceneID;	//���ɍ��V�[����ID

//------------------------------------------------------
//	�V���O���g���f�U�C��
	
public:
	//staatic��m_pInstance�ւ̃A�N�Z�X�p�֐��Q
	//���̂����֐�
	static void CreateInstance();
	//���̂�j������֐�
	static void DestroyInstance();
	//���̂����邩�ǂ����m�F����֐�
	static bool IsNull();
	//���̂��擾����֐�
	static SceneManager* GetInstance();


private:
	SceneManager();
	~SceneManager();
	
private:
	static SceneManager* m_pInstance;

};

#endif

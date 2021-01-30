#ifndef GameManager_h_
#define GameManager_h_

//�Q�[���S�̂̊Ǘ��N���X
class GameManager
{
//------------------------------------------------------
		//	�V���O���g���f�U�C��
public:
	//static��m_pInstance�ւ̃A�N�Z�X�p�֐��Q
	//���̂����֐�
	static void CreateInstance();
	//���̂�j������֐�
	static void DestroyInstance();
	//���̂����邩�ǂ����m�F����֐�
	static bool IsNull();
	//���̂��擾����֐�
	static GameManager* GetInstance();

private:
	//�D���������Ȃ��悤�ɁA�R���X�g���N�^�A�f�X�g���N�^��pravate�����o�[�ɂ���
	GameManager();
	~GameManager();

private:
		//static�ɂ��邱�ƂŁA�N���X�łP�����ł��邱�Ƃ�ۏ؂���	
	static GameManager* m_pInstance;	//�������g�̗B��̎���
};

#endif

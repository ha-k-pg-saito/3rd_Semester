#ifndef InputManager_h_
#define InputManager_h_
#include"../Scene/KeyDefinition.h"

//���͊Ǘ��N���X
class InputManager
{

private:
	struct KeyState
	{
		bool old;		//�O��`�F�b�N���̃t���O���

		bool push;		//�����ꂽ�u��
		bool on;		//��������Ă���
		bool pull;		//�����ꂽ�u��

		KeyState()
			:old(false)
			, push(false)
			, on(false)
			, pull(false)
		{}
	};

public:
	//�L�[���͍X�V
	void Update();
	
	//�L�[�������ꂽ��
	bool IsPush(KeyType key) const;
	bool IsOn(KeyType key) const;
	bool IsPull(KeyType key) const;

private:
	KeyState m_State[KeyType_Max];


//------------------------------------------------------
//	�V���O���g���f�U�C��
public:
	//���̂����֐�
	static void CreateInstance();
	//���̂�j������֐�
	static void DestroyInstance();
	//���̂����邩�ǂ����m�F����֐�
	static bool IsNull();
	//���̂��擾����֐�
	static InputManager* GetInstance();

private:
	InputManager();
	~InputManager();

private:
	static InputManager* m_pInstance;

};



#endif


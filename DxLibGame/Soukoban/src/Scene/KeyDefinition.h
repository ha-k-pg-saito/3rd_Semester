#ifndef KeyDefinition_h_
#define KeyDefinition_h_

#include"DxLib.h"

//�L�[�̎��
enum KeyType
{
	KeyType_Up,		//��ړ�
	KeyType_Down,	//���ړ�
	KeyType_Left,	//���ړ�
	KeyType_Right,	//�E�ړ�
	KeyType_Enter,	//����
	KeyType_Reset,	//���Z�b�g

	KeyType_Max		//�L�[�̎�ސ�
};

//�L�[�̎�ނɑΉ�����A���ۂ̓��͔z��
const int KEY_ASSIGN[KeyType_Max] =
{
	KEY_INPUT_UP,
	KEY_INPUT_DOWN,	
	KEY_INPUT_LEFT,	
	KEY_INPUT_RIGHT,	
	KEY_INPUT_RETURN,	
	KEY_INPUT_R,	
};

#endif

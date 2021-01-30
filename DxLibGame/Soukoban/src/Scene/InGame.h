#ifndef		InGame_h_
#define		InGame_h_

//���N���X
#include"Scene.h"
//��`�w�b�_�[
#include"../Definition.h"

class InGameScene :public SceneBase
{
public:
	//�R���X�g���N�^
	InGameScene();
	//�f�X�g���N�^
	virtual ~InGameScene();

	virtual void Exec();		//�������s��
	virtual void Draw();		//�`����s��

	virtual bool IsEnd() const;

private:
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();

	//�q�ɔԂɊ֌W����֐��Q
private:
	bool IsClear() const;		//��uconst�����O�ł͒l��M��Ȃ�
	void Reset();
	void Move(DirType dir_);

private:
	int m_StageDate[STAGE_HEIGHT][STAGE_WIDTH];
	int m_PlayerX;		//�z����x
	int m_PlayerY;		//�z����y

};

#endif

#ifndef		Scene_h_
#define		Scene_h_

class SceneBase
{
public:
	//�R���X�g���N�^
	SceneBase();
	//�f�X�g���N�^
	virtual ~SceneBase();

	//�������e�͔h���N���X���ƂɈႤ�̂ŁA�������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() = 0;			//�������s��
	virtual void Draw() = 0;			//�`����s��

	virtual bool IsEnd() const;			//�V�[�����I���������ǂ�����Ԃ�

protected:
	void set_Step(int step_);			//�������e�̐؂�ւ�

protected:
	int m_Step;							//�������e���Ǘ�����ϐ�
};

#endif

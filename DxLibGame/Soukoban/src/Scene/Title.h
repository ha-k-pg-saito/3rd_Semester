#ifndef		Title_h_
#define		Title_h_

//���N���X
#include"Scene.h"

class TitleScene :public SceneBase
{
public:
	//�R���X�g���N�^
	TitleScene();
	//�f�X�g���N�^
	virtual ~TitleScene();

	virtual void Exec();		//�������s��
	virtual void Draw();		//�`����s��

	virtual bool IsEnd() const;

private:
	//���S����
	void step_LogoIn();
	//���͑҂�
	void step_Input();
	

};

#endif

#ifndef		Result_h_
#define		Result_h_

//���N���X
#include"Scene.h"

class ResultScene :public SceneBase
{
public:
	//�R���X�g���N�^
	ResultScene();
	//�f�X�g���N�^
	virtual ~ResultScene();

	virtual void Exec();		//�������s��
	virtual void Draw();		//�`����s��

	virtual bool IsEnd() const;

private:
	void step_Input();

};

#endif

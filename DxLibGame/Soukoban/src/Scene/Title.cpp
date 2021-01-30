#include"Title.h"
#include"DxLib.h"
#include"../Manager/InputManager.h"
#include"../Manager/Manager.h"



//���s�X�e�b�v��`
enum
{
	STEP_LOGO_IN,	//���S����҂�
	STEP_INPUT,		//���͑҂�
	STEP_END		//�V�[���I��
};

TitleScene::TitleScene()
{
	set_Step(STEP_LOGO_IN);
}

TitleScene::~TitleScene()
{
}

void TitleScene::Exec()
{
	switch (m_Step)
	{
	case STEP_LOGO_IN: step_LogoIn(); break;
	case STEP_INPUT: step_Input();    break;
	default:					      break;
	}
	
}

void TitleScene::Draw()
{

	int Title = LoadGraph("Res/Title.png");
	DrawGraph(0, 0, Title, FALSE);

	//��ʍ���Ƀf�o�b�O�p�����𑓂ŕ\������
	//DrawString(20, 20, "TitleScene", 255);

}

bool TitleScene::IsEnd() const
{
	return (m_Step>=STEP_END);
}

void TitleScene::step_LogoIn()
{
	set_Step(STEP_INPUT);
}

void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		set_Step(STEP_END);
		SceneManager::SetNextScene(SceneID_InGame);
	}
}
#include"Title.h"
#include"DxLib.h"
#include"../Manager/InputManager.h"
#include"../Manager/Manager.h"



//実行ステップ定義
enum
{
	STEP_LOGO_IN,	//ロゴ入場待ち
	STEP_INPUT,		//入力待ち
	STEP_END		//シーン終了
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

	//画面左上にデバッグ用文字を蒼で表示する
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
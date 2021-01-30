#include"Result.h"
#include"DxLib.h"
#include"../Manager/Manager.h"
#include"../Manager/InputManager.h"

enum
{
	STEP_INPUT,
	STEP_END
};

ResultScene::ResultScene()
{
	set_Step(STEP_INPUT);
}

ResultScene::~ResultScene()
{
}

void ResultScene::Exec()
{
	switch (m_Step)
	{
	case STEP_INPUT: step_Input(); break;
	default:					   break;
	}
}

void ResultScene::Draw()
{
	int Result = LoadGraph("Res/Result.png");
	DrawGraph(0, 0, Result, FALSE);
	//画面左上にデバッグ用文字を蒼で表示する
	//DrawString(20, 20, "ResultScene", 255);
}

bool ResultScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void ResultScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		set_Step(STEP_END);
		SceneManager::SetNextScene(SceneID_Title);
	}
}
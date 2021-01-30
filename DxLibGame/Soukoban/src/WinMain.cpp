#include"DxLib.h"
#include"Manager/Manager.h"
#include"Manager/GameManager.h"
#include"Manager/InputManager.h"


int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
{
	//以下のサイトより関数参照
	//https://dxlib.xsrv.jp/dxfunc.html
	//DXライブラリ初期化処理
	SetOutApplicationLogValidFlag(FALSE);	//ログ出力
	ChangeWindowMode(TRUE);					//ウィンドウモード
	SetGraphMode(350,415,32);				//画面モード変更
	SetBackgroundColor(125, 125, 125);		//背景色
	SetMainWindowText("My倉庫番");		//メニューバーのタイトル
	
	if (DxLib_Init() == -1)		
	{
		//エラーが起きたら直ちに終了
		return -1;		
	}

	//描画先を裏の画面に設定（詳しくは上記のサイト参照）
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームを始める前の初期化処理
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	

	//ゲームループ
	while (true)
	{
		//Windowsのメッセージ処理に失敗したか、閉じられたら終了
		if (ProcessMessage()!=0)
		{
			break;
		}

		//DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();

		//点を打つ
		//DrawPixel(320, 240, GetColor(255, 255, 255));
		SetFontSize(40);
		//文字出力
		//DrawString(150,200,"ApexLegends",100);
		
		//シングルトンの実態を取得
		InputManager* pInputMng = InputManager::GetInstance();
		SceneManager* pSceneMng = SceneManager::GetInstance();

		//処理
		pInputMng->Update();
		pSceneMng->Exec();

		//表示
		pSceneMng->Draw();

		//DxLibのお約束：画面更新
		ScreenFlip();
	}

	//ゲーム終了後の後始末
	//シングルトンに限らず、作った順番と逆で破棄する
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	//DXライブラリ使用の終了処理
	DxLib_End();			

	//ソフトの終了
	return 0;				
}
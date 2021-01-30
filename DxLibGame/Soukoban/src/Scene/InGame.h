#ifndef		InGame_h_
#define		InGame_h_

//基底クラス
#include"Scene.h"
//定義ヘッダー
#include"../Definition.h"

class InGameScene :public SceneBase
{
public:
	//コンストラクタ
	InGameScene();
	//デストラクタ
	virtual ~InGameScene();

	virtual void Exec();		//処理を行う
	virtual void Draw();		//描画を行う

	virtual bool IsEnd() const;

private:
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();

	//倉庫番に関係する関数群
private:
	bool IsClear() const;		//後置const＝＞外では値を弄らない
	void Reset();
	void Move(DirType dir_);

private:
	int m_StageDate[STAGE_HEIGHT][STAGE_WIDTH];
	int m_PlayerX;		//配列上のx
	int m_PlayerY;		//配列上のy

};

#endif

#ifndef		Title_h_
#define		Title_h_

//基底クラス
#include"Scene.h"

class TitleScene :public SceneBase
{
public:
	//コンストラクタ
	TitleScene();
	//デストラクタ
	virtual ~TitleScene();

	virtual void Exec();		//処理を行う
	virtual void Draw();		//描画を行う

	virtual bool IsEnd() const;

private:
	//ロゴ入場
	void step_LogoIn();
	//入力待ち
	void step_Input();
	

};

#endif

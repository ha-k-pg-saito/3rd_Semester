#ifndef		Result_h_
#define		Result_h_

//基底クラス
#include"Scene.h"

class ResultScene :public SceneBase
{
public:
	//コンストラクタ
	ResultScene();
	//デストラクタ
	virtual ~ResultScene();

	virtual void Exec();		//処理を行う
	virtual void Draw();		//描画を行う

	virtual bool IsEnd() const;

private:
	void step_Input();

};

#endif

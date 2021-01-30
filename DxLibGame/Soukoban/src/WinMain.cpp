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
	//�ȉ��̃T�C�g���֐��Q��
	//https://dxlib.xsrv.jp/dxfunc.html
	//DX���C�u��������������
	SetOutApplicationLogValidFlag(FALSE);	//���O�o��
	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h
	SetGraphMode(350,415,32);				//��ʃ��[�h�ύX
	SetBackgroundColor(125, 125, 125);		//�w�i�F
	SetMainWindowText("My�q�ɔ�");		//���j���[�o�[�̃^�C�g��
	
	if (DxLib_Init() == -1)		
	{
		//�G���[���N�����璼���ɏI��
		return -1;		
	}

	//�`���𗠂̉�ʂɐݒ�i�ڂ����͏�L�̃T�C�g�Q�Ɓj
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����n�߂�O�̏���������
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	

	//�Q�[�����[�v
	while (true)
	{
		//Windows�̃��b�Z�[�W�����Ɏ��s�������A����ꂽ��I��
		if (ProcessMessage()!=0)
		{
			break;
		}

		//DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();

		//�_��ł�
		//DrawPixel(320, 240, GetColor(255, 255, 255));
		SetFontSize(40);
		//�����o��
		//DrawString(150,200,"ApexLegends",100);
		
		//�V���O���g���̎��Ԃ��擾
		InputManager* pInputMng = InputManager::GetInstance();
		SceneManager* pSceneMng = SceneManager::GetInstance();

		//����
		pInputMng->Update();
		pSceneMng->Exec();

		//�\��
		pSceneMng->Draw();

		//DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();
	}

	//�Q�[���I����̌�n��
	//�V���O���g���Ɍ��炸�A��������ԂƋt�Ŕj������
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	//DX���C�u�����g�p�̏I������
	DxLib_End();			

	//�\�t�g�̏I��
	return 0;				
}
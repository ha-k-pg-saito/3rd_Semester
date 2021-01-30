#include"InGame.h"
#include"DxLib.h"
#include"../Manager/Manager.h"
#include"../Manager/InputManager.h"

int char_dir = 0;
int i = 0;

enum
{
	STEP_STARTJINGLE,
	STEP_INPUT,
	STEP_CLEARJINGLE,
	STEP_END
};

//�q�ɔԃT���v���X�e�[�W
const int g_SampleStage[STAGE_HEIGHT][STAGE_WIDTH] =
{

	0,0,0,1,1,1,1,1,0,0,0,
	0,0,0,1,3,3,3,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	1,1,1,1,1,0,1,1,1,1,1,
	1,0,0,4,0,0,1,0,0,0,1,
	1,0,1,0,0,4,0,4,0,0,1,
	1,0,0,0,1,1,1,0,0,0,1,
	1,1,1,0,1,0,1,0,1,1,1,
	0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,0,0,2,0,0,1,0,0,
	0,0,1,1,1,0,1,1,1,0,0,

};

InGameScene::InGameScene()
	:m_PlayerX(0)
	,m_PlayerY(0)
{
	Reset();
	set_Step(STEP_STARTJINGLE);
}

InGameScene::~InGameScene()
{
}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_STARTJINGLE: step_StartJingle();		break;
	case STEP_INPUT: step_Input();					break;
	case STEP_CLEARJINGLE:step_ClearJingle();	default:	break;
	}
}

void InGameScene::Draw()
{
//�X�e�[�W�̒��g�ƃv���C����`��

	
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			
			switch (m_StageDate[y][x])
			{
			case ObjectType_Ground:
				LoadGraphScreen(x * CHIP_WIDTH, y * CHIP_HEIGHT, "Res/ground.png", TRUE);
				break;
			case ObjectType_Wall:
				DrawBox(x * CHIP_WIDTH,y * CHIP_HEIGHT,x * CHIP_WIDTH + CHIP_WIDTH,y * CHIP_HEIGHT + CHIP_HEIGHT,GetColor(255, 255, 255),TRUE);
				LoadGraphScreen(x * CHIP_WIDTH, y * CHIP_HEIGHT, "Res/block.png", TRUE);
				break;
			case ObjectType_Target:
				LoadGraphScreen(x * CHIP_WIDTH, y * CHIP_HEIGHT, "Res/crate_00.png", TRUE);
				break;
			case ObjectType_UnsetCrate:
				LoadGraphScreen(x * CHIP_WIDTH, y * CHIP_HEIGHT, "Res/crate_01.png", TRUE);
				break;
			case ObjectType_SetCrate:
				LoadGraphScreen(x * CHIP_WIDTH, y * CHIP_HEIGHT, "Res/crate_02.png", TRUE);
				break;
			}

		}
	}


	/*int Player = LoadGraph("Res/player_00.png");
	DrawGraph(m_PlayerX * CHIP_WIDTH,m_PlayerY * CHIP_HEIGHT, Player, FALSE);*/

	LoadGraphScreen(m_PlayerX * CHIP_WIDTH,m_PlayerY* CHIP_HEIGHT,"Res/player_00.png",TRUE);

	int Player_Up[3];
	int Player_Down[3];
	int Player_Left[3];
	int Player_Right[3];

	Player_Up[0] = LoadGraph("Res/player_00.png");
	Player_Up[1] = LoadGraph("Res/player_01.png");
	Player_Up[2] = LoadGraph("Res/player_02.png");
	Player_Down[0] = LoadGraph("Res/player_03.png");
	Player_Down[1] = LoadGraph("Res/player_04.png");
	Player_Down[2] = LoadGraph("Res/player_05.png");
	Player_Left[0] = LoadGraph("Res/player_06.png");
	Player_Left[1] = LoadGraph("Res/player_07.png");
	Player_Left[2] = LoadGraph("Res/player_08.png");
	Player_Right[0] = LoadGraph("Res/player_09.png");
	Player_Right[1] = LoadGraph("Res/player_10.png");
	Player_Right[2] = LoadGraph("Res/player_11.png");

	if (IsClear())
	{

		DrawString(20, 200, "Congratulation!!", GetColor(0, 0, 255));

	}

	switch (char_dir)
	{

	case 0:
		DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, Player_Up[i], TRUE);		break;
		//DrawExtendGraph(m_PlayerX, m_PlayerY, m_PlayerX+CHIP_WIDTH, m_PlayerY+CHIP_HEIGHT, Player_Up[i], FALSE);		break;	
	case 1:
		DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, Player_Down[i], TRUE);		break;
	case 2:
		DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, Player_Left[i], TRUE);		break;
	case 3:
		DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, Player_Right[i], TRUE);		break;
	
	}

	//��ʍ���Ƀf�o�b�O�p�����𑓂ŕ\������
	//DrawString(20, 20, "InGameScene", 255);

}

bool InGameScene::IsEnd() const
{
	return (m_Step >= STEP_END);
}

//�J�n�W���O��
void InGameScene::step_StartJingle()
{
	set_Step(STEP_INPUT);
}


void InGameScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Reset))
	{
			Reset();
			
	}

	else if (pInputMng->IsPush(KeyType_Up))
	{
		Move(DirType_Up);
	}
	else if (pInputMng->IsPush(KeyType_Down))
	{
		Move(DirType_Down);
	}
	else if (pInputMng->IsPush(KeyType_Left))
	{
		Move(DirType_Left);
	}
	else if (pInputMng->IsPush(KeyType_Right))
	{
		Move(DirType_Right);
	}

	i++;
	if (i > 2)
	{
		i = 0;
	}

	if (IsClear())
	{
		
		set_Step(STEP_CLEARJINGLE);

	}
}

void InGameScene::step_ClearJingle()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_Enter))
	{
		set_Step(STEP_END);
		SceneManager::SetNextScene(SceneID_Result);
	}
}

//�Q�[���N���A����
bool InGameScene::IsClear() const
{
	//��dfor����m_StageDate�̔z���������
	//�P�ł�ObjectType_UnsetCrate������������false��Ԃ�
	
	for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			if (m_StageDate[y][x]==ObjectType_UnsetCrate)
			{
				return false;
			}
		}
	}

	//for���𔲂��Ă�����ObjectType_UnsetCrate�������������ƂɂȂ�A
	//�t���I�ɂ��ׂĂ�ObjectType_SetCrate��ԂɂȂ��Ă���i�����Q�[���N���A�j
	return true;
}


void InGameScene::Reset()
{

	//���O���f�[�^��ǂݍ��񂾂�A�X�e�[�W�𑝂₷�ꍇ�͏������e���l����
	//�X�e�[�W������
for (int y = 0; y < STAGE_HEIGHT; y++)
	{
		for (int x = 0; x < STAGE_WIDTH; x++)
		{
			m_StageDate[y][x] = g_SampleStage[y][x];
			if (m_StageDate[y][x] == ObjectType_Player)
			{

				m_PlayerX = x;
				m_PlayerY = y;
				m_StageDate[y][x] = ObjectType_Ground;

			}
		}
	}
	set_Step(STEP_STARTJINGLE);

}


void InGameScene::Move(DirType dir_)
{
	//DirType���͈͓���
	if(dir_<DirType_Up&&dir_>=DirType_Max)
	{
		return;
	}

	int next_x = m_PlayerX;		//���̈ړ���X
	int next_y = m_PlayerY;		//���̈ړ���Y
	int next2_x = m_PlayerX;	//���̎�X
	int next2_y = m_PlayerY;	//���̎�Y

	

	//�ړ������ɉ����č��W��ݒ�
	//next_x(y),next2_x(y)�̒l�����ꂼ��ݒ肷��
	switch (dir_)
	{
	case DirType_Up:
		char_dir = 0;
		next_y -= 1;
		next2_y -= 2;
		break;
	case DirType_Down:
		char_dir = 1;
		next_y += 1;
		next2_y += 2;
		break;
	case DirType_Left:
		char_dir = 2;
		next_x -= 1;
		next2_x -= 2;
		break;
	case DirType_Right:
		char_dir = 3;
		next_x += 1;
		next2_x += 2;
		break;
	}

	//�ړ��悪��ʊO�Ȃ�A�֐��𔲂���
	if (next_x<0||next_y<0||next_x>=(STAGE_WIDTH-1)||next_y>=(STAGE_HEIGHT-1))
	{
		return;
	}

	//�ʏ�ړ��i�ړ��悪Player�̏���}�b�v�`�b�v�̎�ނ�������
	//m_PlayerX(Y)�����ꂼ��next_x(y)�ŏ㏑��)
	
	if (m_StageDate[next_y][next_x]==ObjectType_Ground||m_StageDate[next_y][next_x]==ObjectType_Target)
	{
		m_PlayerX = next_x;
		m_PlayerY = next_y;
	}

	//�ړ���Ɂi�N���[�g�j������ꍇ
	else if (m_StageDate[next_y][next_x]==ObjectType_UnsetCrate||m_StageDate[next_y][next_x]==ObjectType_SetCrate)
	{
		
		//�Q�悪��ʊO���`�F�b�N
		if (next2_x<0 || next2_y<0 || next2_x>=(STAGE_WIDTH - 1) || next2_y>=(STAGE_HEIGHT - 1))
		{
			return;
		}

		//�Q�悪�ړ��ł��Ȃ������`�F�b�N
		//�ړ��ł���}�b�v�`�b�v�łȂ��ꍇ�Ƃ�������
		if (m_StageDate[next2_y][next2_x] != ObjectType_Ground && m_StageDate[next2_y][next2_x] != ObjectType_Target)
		{
			return;
		}

		//�ׂ̈ʒu�𔻒肷��
		if (m_StageDate[next_y][next_x] == ObjectType_UnsetCrate)
		{
			m_StageDate[next_y][next_x] = ObjectType_Ground;
		}
		else
		{
			m_StageDate[next_y][next_x] = ObjectType_Target;
		}
			
		//�Q��ɔ���z�u����
		if (m_StageDate[next2_y][next2_x] == ObjectType_Ground)
		{
			m_StageDate[next2_y][next2_x] = ObjectType_UnsetCrate;
		}
		else if((m_StageDate[next2_y][next2_x] == ObjectType_Target))
		{
			m_StageDate[next2_y][next2_x] = ObjectType_SetCrate;
		}

		//�v���C���[���ړ�������
		m_PlayerX = next_x;
		m_PlayerY = next_y;
	}
}
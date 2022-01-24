#include "Field.h"
#include "Player.h"
#include "Monster.h"

CField::CField()
	:m_pPlayer(nullptr), m_pMonster(nullptr)
{
}


CField::~CField()
{
	Release();
}

void CField::Initialize(void)
{
}

void CField::Progress(void)
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.초급 2.중급 3.고급 4.나가기" << endl;
		cout << "===============================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		int iA = 10;
		CPlayer player;

		switch (iSelect)
		{
		case 1:
			m_pMonster = new CMonster(INFO("초급 몬스터", 5, 30, 1));
			m_pMonster->Initialize();
			break;
		case 2:
			m_pMonster = new CMonster(INFO("중급 몬스터", 10, 40, 2));
			m_pMonster->Initialize();
			break;
		case 3:
			m_pMonster = new CMonster(INFO("고급 몬스터", 20, 100, 3));
			m_pMonster->Initialize();
			break;
		case 4:
			return;
		default:
			continue;

		}

		switch (Combat())
		{
		case WIN:
			static_cast<CPlayer*>(m_pPlayer)->CombatWin(static_cast<CMonster*>(m_pMonster)->GetExp(), static_cast<CMonster*>(m_pMonster)->GetGold());
			break;
		case LOSE:
			static_cast<CPlayer*>(m_pPlayer)->CombatLose();
			break;
		case RUN:
			static_cast<CPlayer*>(m_pPlayer)->CombatRun();
			break;
		default:
			break;
		}

		SafeDelete(m_pMonster);
	}
}

void CField::Release(void)
{
	SafeDelete(m_pMonster);
}

void CField::SetPlayer(CObj * pPlayer)
{
	m_pPlayer = pPlayer;
}

COMBAT CField::Combat()
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pMonster->Render();
		cout << "1.전투 2.도망" << endl;
		cout << "===========================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			m_pPlayer->SetHp(-m_pMonster->GetAtt());
			m_pMonster->SetHp(-m_pPlayer->GetAtt());
			break;
		case 2:
			return RUN;
		default:
			continue;
		}

		if (0 >= m_pPlayer->GetHp())
		{
			cout << "플레이어 사망!" << endl;
			system("pause");
			return LOSE;
		}

		if (0 >= m_pMonster->GetHp())
		{
			cout << "전투 승리!" << endl;
			system("pause");
			return WIN;
		}
	}
}

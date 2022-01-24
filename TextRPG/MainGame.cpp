#include "MainGame.h"
#include "Player.h"
#include "Field.h"
#include "Shop.h"
#include "Inven.h"
#include "Item.h"

CMainGame::CMainGame()
	:m_pField(nullptr), m_pShop(nullptr), m_pInven(nullptr)
{
	m_pPlayer = nullptr;
}


CMainGame::~CMainGame()
{
	Release();
}

bool CMainGame::Initialize(void)
{
	SelectPlayer();

	if (nullptr == m_pPlayer)
		return false;

	if (nullptr == m_pField)
	{
		m_pField = new CField;
		m_pField->Initialize();
	}
	
	if (nullptr == m_pShop)
	{
		m_pShop = new CShop;
		m_pShop->Initialize();
	}

	if (nullptr == m_pInven)
	{
		m_pInven = new CInven;
		m_pInven->Initialize();
	}

	m_pField->SetPlayer(m_pPlayer);
	m_pShop->SetPlayer(m_pPlayer);
	m_pInven->SetPlayer(m_pPlayer);

	m_pShop->SetInven(m_pInven);

	return true;
}

void CMainGame::Progress(void)
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.던전 2.인벤 3.상점 3.저장 4.종료" << endl;
		cout << "===============================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			m_pField->Progress();
			break;
		case 2:
			m_pInven->Update();
			break;
		case 3:
			m_pShop->Update();
			continue;
		case 4:
			SaveData();
			break;
		case 5:
			return;
		default:
			continue;

		}
	}
}


void CMainGame::Release(void)
{
	SafeDelete(m_pField);
	SafeDelete(m_pShop);
	SafeDelete(m_pInven);

	SafeDelete(m_pPlayer);
}

void CMainGame::SelectPlayer()
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		cout << "1.전사 2.마법사 3.도적 4.불러오기 5.종료" << endl;
		cout << "===========================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			m_pPlayer = new CPlayer(INFO("전사", 10, 200));
			m_pPlayer->Initialize();
			return;
		case 2:
			m_pPlayer = new CPlayer(INFO("마법사", 30, 100));
			m_pPlayer->Initialize();
			return;
		case 3:
			m_pPlayer = new CPlayer(INFO("도적", 20, 150));
			m_pPlayer->Initialize();
			return;
		case 4:
			LoadData();
			return;
		case 5:
			return;
		default:
			continue;
		}
	}
}

void CMainGame::SaveData()
{
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/Save.dat", "wb");

	if (0 == err)
	{
		fwrite(&static_cast<CPlayer*>(m_pPlayer)->SaveData(), sizeof(INFO), 1, fp);

		for (size_t i = 0; i < m_pInven->GetInvenSize(); ++i)
		{
			fwrite(&m_pInven->GetItemInfo(i), sizeof(INFO), 1, fp);
			fwrite(&m_pInven->GetItemType(i), sizeof(TYPE), 1, fp);
			fwrite(&m_pInven->GetItemState(i), sizeof(STATE), 1, fp);
		}

		cout << "저장 성공!" << endl;
		fclose(fp);
	}
	else
		cout << "저장 실패!" << endl;

	system("pause");
}

void CMainGame::LoadData()
{

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/Save.dat", "rb");

	if (0 == err)
	{
		INFO tTemp = {};
		TYPE	eType = TYPE_END;
		STATE	eState = STATE_END;

		fread(&tTemp, sizeof(INFO), 1, fp);

		m_pPlayer = new CPlayer;
		m_pPlayer->Initialize();

		m_pInven = new CInven;
		m_pInven->Initialize();

		static_cast<CPlayer*>(m_pPlayer)->LoadData(tTemp);

		while (true)
		{
			fread(&tTemp, sizeof(INFO), 1, fp);
			fread(&eType, sizeof(TYPE), 1, fp);
			int iCnt = fread(&eState, sizeof(STATE), 1, fp);

			if (1 > iCnt)
				break;

			CObj* pItem = new CItem(tTemp);
			static_cast<CItem*>(pItem)->SetType(eType);
			static_cast<CItem*>(pItem)->SetState(eState);

			m_pInven->LoadItem(pItem);

			if (EQUIP == eState)
				static_cast<CPlayer*>(m_pPlayer)->LoadItem(pItem, eType);
		}

		cout << "불러오기 성공!" << endl;
		fclose(fp);
	}
	else
		cout << " 불러오기 실패! " << endl;

	system("pause");

}


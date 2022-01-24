#include "Shop.h"
#include "Player.h"
#include "Item.h"
#include "Inven.h"

CShop::CShop()
	:m_pPlayer(nullptr)
{
	memset(m_pItem, 0, sizeof(m_pItem));
}


CShop::~CShop()
{
	Release();
}

void CShop::Initialize(void)
{
	CObj*	pItem = new CItem(INFO("�ʱ� ��", 10, 0, 1, 100));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(SWORD);
	m_pItem[LEVEL1][SWORD] = pItem;

	pItem = new CItem(INFO("�ʱ� ��", 0, 50, 1, 100));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(ARMOR);
	m_pItem[LEVEL1][ARMOR] = pItem;

	pItem = new CItem(INFO("�߱� ��", 50, 0, 1, 1000));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(SWORD);
	m_pItem[LEVEL2][SWORD] = pItem;

	pItem = new CItem(INFO("�߱� ��", 0, 100, 1, 1000));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(ARMOR);
	m_pItem[LEVEL2][ARMOR] = pItem;

	pItem = new CItem(INFO("��� ��", 100, 0, 1, 10000));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(SWORD);
	m_pItem[LEVEL3][SWORD] = pItem;

	pItem = new CItem(INFO("��� ��", 0, 200, 1, 10000));
	pItem->Initialize();
	static_cast<CItem*>(pItem)->SetType(ARMOR);
	m_pItem[LEVEL3][ARMOR] = pItem;
}

void CShop::Update(void)
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.�ʱ� 2.�߱� 3.��� 4.�Ǹ� 5.������" << endl;
		cout << "===========================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Render(LEVEL1);
			break;
		case 2:
			Render(LEVEL2);
			break;
		case 3:
			Render(LEVEL3);
			break;
		case 4:
			SellItem();
			break;
		case 5:
			return;
		default:
			continue;
		}
	}
}

void CShop::Render(LEVEL eLevel)
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pItem[eLevel][SWORD]->Render();
		m_pItem[eLevel][ARMOR]->Render();
		cout << "1.���ⱸ�� 2.������ 3.������" << endl;
		cout << "===========================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			BuyItem(m_pItem[eLevel][SWORD]);
			break;
		case 2:
			BuyItem(m_pItem[eLevel][ARMOR]);
			break;
		case 3:
			return;
		default:
			continue;
		}

	}
}

void CShop::Release(void)
{
	for (int i = 0; i < LEVEL_END; ++i)
	{
		for (int j = 0; j < TYPE_END; ++j)
			SafeDelete(m_pItem[i][j]);
	}
}

void CShop::BuyItem(CObj * pItem)
{
	if (m_pPlayer->GetGold() >= pItem->GetGold()
		&& m_pInven->BuyItem(pItem))
	{
		m_pPlayer->SetGold(-pItem->GetGold());
		cout << "���� ����!" << endl;
	}
	else
		cout << "���� ����!" << endl;

	system("pause");
}

void CShop::SellItem()
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		m_pInven->Render();
		cout << "0) ������" << endl;
		cout << "===========================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;
		--iSelect;

		if (0 > iSelect)
			return;

		int iGold = 0;

		if (m_pInven->SellItem(iSelect, &iGold))
		{
			m_pPlayer->SetGold(iGold);
			cout << "�Ǹ� ����!" << endl;
		}
		else
			cout << "�Ǹ� ����!" << endl;

		system("pause");
	}
}

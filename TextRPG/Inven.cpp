#include "Inven.h"
#include "Player.h"
#include "Item.h"

CInven::CInven()
	:m_pPlayer(nullptr), m_iSize(5)
{
}


CInven::~CInven()
{
	Release();
}

void CInven::Initialize(void)
{
	m_vecInven.reserve(m_iSize);
}

void CInven::Update(void)
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1.장착 2.해제 3.나가기" << endl;
		cout << "===========================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			EquipItem();
			break;
		case 2:
			UnEquipItem();
			break;
		case 3:
			return;
		default:
			continue;
		}
	}
}

void CInven::Render(void)
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
	{
		cout << i + 1 << ") " << endl;
		m_vecInven[i]->Render();
	}
}

void CInven::Release(void)
{
	for (size_t i = 0; i < m_vecInven.size(); ++i)
		SafeDelete(m_vecInven[i]);

	m_vecInven.clear();
}

bool CInven::BuyItem(CObj * pItem_)
{
	if (m_vecInven.size() >= m_iSize)
		return false;

	CItem* pTemp = static_cast<CItem*>(pItem_);
	CObj* pItem = new CItem(*pTemp);
	m_vecInven.push_back(pItem_);

	//m_vecInven.push_back(new CItem(*static_cast<CItem*>(_pItem)));

	return true;
}

bool CInven::SellItem(int iIdx, int * pGold)
{
	if (m_vecInven.size() <= (size_t)iIdx)
		return false;

	if (EQUIP == static_cast<CItem*>(m_vecInven[iIdx])->GetState())
		return false;

	vector<CObj*>::iterator		iter = m_vecInven.begin();
	iter += iIdx;

	*pGold = (*iter)->GetGold() >> 1;

	SafeDelete(*iter);
	m_vecInven.erase(iter);

	return true;
}

void CInven::EquipItem()
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		Render();
		cout << "0) 나가기" << endl;
		cout << "===========================================" << endl;
		cout << "입력: ";
		cin >> iSelect;
		--iSelect;

		if (0 > iSelect)
			return;

		if (m_vecInven.size() <= (size_t)iSelect)
			continue;

		static_cast<CPlayer*>(m_pPlayer)->EquipItem(m_vecInven[iSelect]);
	}
}

void CInven::UnEquipItem()
{
	int		iSelect = 0;

	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "0) 나가기" << endl;
		cout << "===========================================" << endl;
		cout << "입력: ";
		cin >> iSelect;
		--iSelect;

		if (0 > iSelect)
			return;

		if (TYPE_END <= iSelect)
			continue;

		static_cast<CPlayer*>(m_pPlayer)->UnEquipItem(iSelect);
	}
}

const size_t CInven::GetInvenSize() const
{
	return size_t();
}

const INFO & CInven::GetItemInfo(int iIdx) const
{
	return static_cast<CItem*>(m_vecInven[iIdx])->GetInfo();
}

const TYPE & CInven::GetItemType(int iIdx) const
{
	return static_cast<CItem*>(m_vecInven[iIdx])->GetType();
}

const STATE & CInven::GetItemState(int iIdx) const
{
	return static_cast<CItem*>(m_vecInven[iIdx])->GetState();
}

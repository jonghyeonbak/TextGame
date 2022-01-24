#include "Player.h"
#include "Item.h"


CPlayer::CPlayer()
{
	memset(&m_tInfo, 0, sizeof(m_tInfo));
	memset(&m_pItem, 0, sizeof(m_pItem));
}

CPlayer::CPlayer(INFO& rInfo)
	: CObj(rInfo)
{
	memset(&m_pItem, 0, sizeof(m_pItem));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
}

void CPlayer::Render()
{
	cout << "이름: " << m_tInfo.szName << endl;
	cout << "공격력: " << m_tInfo.iAtt << endl;
	cout << "체력: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "레벨: " << m_tInfo.iLevel << "  ( " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << " )" << endl;
	cout << "골드: " << m_tInfo.iGold << endl;
	cout << "===========================================" << endl;
	ItemInfo();

}

void CPlayer::Release()
{
}



INFO& CPlayer::SaveData()
{
	return m_tInfo;
}

void CPlayer::LoadData(INFO& rInfo)
{
	memcpy(&m_tInfo, &rInfo, sizeof(INFO));
}

void CPlayer::CombatWin(int iExp, int iGold)
{
	m_tInfo.iExp += iExp;
	m_tInfo.iGold += iGold;

	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		m_tInfo.iExp -= m_tInfo.iMaxExp;
		++m_tInfo.iLevel;
		m_tInfo.iAtt += 10;
		m_tInfo.iMaxHp += 50;
		m_tInfo.iHp = m_tInfo.iMaxHp;
		m_tInfo.iMaxExp += 100;
	}
}

void CPlayer::CombatLose()
{
	m_tInfo.iHp = m_tInfo.iMaxHp;
	m_tInfo.iExp >>= 1;
	m_tInfo.iGold >>= 1;
}

void CPlayer::CombatRun()
{
	m_tInfo.iExp = 0;
	m_tInfo.iGold = 0;
}

void CPlayer::EquipItem(CObj * pItem)
{
	TYPE eType = static_cast<CItem*>(pItem)->GetType();

	if (m_pItem[eType])
	{
		ItemAbility(-m_pItem[eType]->GetAtt(), -m_pItem[eType]->GetHp());
		static_cast<CItem*>(m_pItem[eType])->SetState(UNEQUIP);
		m_pItem[eType] = nullptr;
	}

	ItemAbility(pItem->GetAtt(), pItem->GetHp());
	static_cast<CItem*>(pItem)->SetState(EQUIP);
	m_pItem[eType] = pItem;
}

void CPlayer::UnEquipItem(int iIdx)
{
	if (m_pItem[iIdx])
	{
		ItemAbility(-m_pItem[iIdx]->GetAtt(), -m_pItem[iIdx]->GetHp());
		static_cast<CItem*>(m_pItem[iIdx])->SetState(UNEQUIP);
		m_pItem[iIdx] = nullptr;
	}
}

void CPlayer::ItemAbility(int iAtt, int iMaxHp)
{
	m_tInfo.iAtt += iAtt;
	m_tInfo.iMaxHp += iMaxHp;
}

void CPlayer::ItemInfo()
{
	for (int i = 0; i < TYPE_END; ++i)
	{
		if (m_pItem[i])
		{
			cout << i + 1 << ") " << m_pItem[i]->GetName() << endl;
			cout << "===========================================" << endl;
		}
	}
}

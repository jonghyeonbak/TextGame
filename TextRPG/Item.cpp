#include "Item.h"



CItem::CItem()
	:m_eType(TYPE_END), m_eState(STATE_END)
{
}

CItem::CItem(INFO & rInfo)
	:CObj(rInfo), m_eType(TYPE_END), m_eState(STATE_END)
{
}



CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
	m_eState = UNEQUIP;
}

void CItem::Render()
{
	if (EQUIP == m_eState)
		cout << "<<착용 중 >>" << endl;

	cout << "이름: " << m_tInfo.szName << endl;
	cout << "공격력: + " << m_tInfo.iAtt << endl;
	cout << "체력: + " << m_tInfo.iMaxHp << endl;
	cout << "골드: " << m_tInfo.iGold << endl;
	cout << "===========================================" << endl;

}

void CItem::Release()
{
}

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
		cout << "<<���� �� >>" << endl;

	cout << "�̸�: " << m_tInfo.szName << endl;
	cout << "���ݷ�: + " << m_tInfo.iAtt << endl;
	cout << "ü��: + " << m_tInfo.iMaxHp << endl;
	cout << "���: " << m_tInfo.iGold << endl;
	cout << "===========================================" << endl;

}

void CItem::Release()
{
}

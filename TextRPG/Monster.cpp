#include "Monster.h"


CMonster::CMonster()
{
	memset(&m_tInfo, 0, sizeof(m_tInfo));
}

CMonster::CMonster(INFO& rInfo)
	 : CObj(rInfo)
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.iMaxExp = rand() % 50 + ((m_tInfo.iLevel - 1) * 50) + 1;
	m_tInfo.iExp = m_tInfo.iMaxExp;
	m_tInfo.iGold = rand() % 50 + ((m_tInfo.iLevel - 1) * 50) + 1;

}

void CMonster::Render(void)
{
	cout << "�̸�: " << m_tInfo.szName << endl;
	cout << "���ݷ�: " << m_tInfo.iAtt << endl;
	cout << "ü��: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "===========================================" << endl;

}

void CMonster::Release(void)
{
}




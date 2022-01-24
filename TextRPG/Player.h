#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
public:
	CPlayer();
	CPlayer(INFO& rInfo);
	virtual ~CPlayer();

public:
	virtual void Initialize();
	virtual void Render();
	virtual void Release();

public:
	INFO& SaveData();
	void LoadData(INFO& rInfo);
	void LoadItem(CObj* _pItem, TYPE _eType) { m_pItem[_eType] = _pItem; }

public:
	void CombatWin(int iExp, int iGold);
	void CombatLose();
	void CombatRun();

public:
	void EquipItem(CObj* pItem);
	void UnEquipItem(int iIdx);
	void ItemAbility(int iAtt, int iMaxHp);
	void ItemInfo();

private:
	CObj* m_pItem[TYPE_END];
};


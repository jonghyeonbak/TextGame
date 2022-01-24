#pragma once
#include "Include.h"

class CObj;
class CInven
{
public:
	CInven();
	~CInven();

public:
	void Initialize(void);
	void Update(void);
	void Render(void);
	void Release(void);

public:
	bool BuyItem(CObj* pItem);
	bool SellItem(int iIdx, int* pGold);

public:
	void EquipItem();
	void UnEquipItem();

public:
	const size_t GetInvenSize() const;
	const INFO& GetItemInfo(int iIdx) const;
	const TYPE& GetItemType(int iIdx) const;
	const STATE& GetItemState(int iIdx) const;

public:
	void LoadItem(CObj* pItem) { m_vecInven.push_back(pItem); }

public:
	void SetPlayer(CObj* pPlayer) { m_pPlayer = pPlayer; }

private:
	CObj*				m_pPlayer;

	vector<CObj*>		m_vecInven;
	const size_t		m_iSize;
};


#pragma once
#include "Include.h"

class CObj;
class CInven;
class CShop
{
public:
	CShop();
	~CShop();

public:
	void Initialize(void);
	void Update(void);
	void Render(LEVEL eLevel);
	void Release(void);

public:
	void BuyItem(CObj* pItem);
	void SellItem();

public:
	void SetPlayer(CObj* pPlayer) { m_pPlayer = pPlayer; }
	void SetInven(CInven* pInven) { m_pInven = pInven; }

private:
	CObj* m_pPlayer;
	CObj* m_pItem[LEVEL_END][TYPE_END];

	CInven* m_pInven;
};


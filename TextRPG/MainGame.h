#pragma once
#include "Include.h"

class CObj;
class CField;
class CShop;
class CInven;
class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	bool Initialize(void);
	void Progress(void);
	void Release(void);

private:
	void SelectPlayer();

private:
	void SaveData();
	void LoadData();

private:
	CObj* m_pPlayer;
	CField* m_pField;
	CShop* m_pShop;
	CInven* m_pInven;
};


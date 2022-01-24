#pragma once
#include "Include.h"

class CObj;
class CField
{
public:
	CField();
	~CField();

public:
	void Initialize(void);
	void Progress(void);
	void Release(void);

public:
	void SetPlayer(CObj* pPlayer);

private:
	COMBAT Combat();

private:
	CObj* m_pPlayer;
	CObj* m_pMonster;
};


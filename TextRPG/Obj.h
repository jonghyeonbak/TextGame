#pragma once

#include "Include.h"

class CObj
{
public:
	CObj();
	CObj(INFO& rInfo);
	virtual ~CObj();

public:
	virtual void Initialize() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	int GetAtt();
	int GetHp();
	int GetGold() { return m_tInfo.iGold; }
	int GetExp() { return m_tInfo.iExp; }
	const char* GetName() const { return m_tInfo.szName; }

public:
	void SetHp(int iAtt);
	void SetGold(int iGold) { m_tInfo.iGold += iGold; }

protected:
	INFO	m_tInfo;
};


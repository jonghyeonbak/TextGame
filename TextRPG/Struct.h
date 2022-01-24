#pragma once

#include <iostream>
using namespace std;

typedef struct tagInfo {
		
	char szName[16];
	int  iAtt;
	int	 iHp;
	int  iMaxHp;
	int  iExp;
	int  iMaxExp;
	int  iLevel;
	int  iGold;
	bool bCheck;

	tagInfo() { memset(this, 0, sizeof(tagInfo)); }

	tagInfo(char* pName, int iAtt, int iMaxHp)
		:iAtt(iAtt), iMaxHp(iMaxHp), iHp(iMaxHp)
		, iLevel(1), iMaxExp(100), iExp(0), iGold(0)
	{
		strcpy_s(szName, 16, pName);
	}

	tagInfo(char* pName, int iAtt, int iMaxHp, int iLevel)
		:iAtt(iAtt), iMaxHp(iMaxHp), iHp(iMaxHp)
		, iLevel(iLevel), iMaxExp(100), iExp(0), iGold(0)
	{
		strcpy_s(szName, 16, pName);
	}

	tagInfo(char* pName, int iAtt, int iMaxHp, int iLevel, int iGold)
		:iAtt(iAtt), iMaxHp(iMaxHp), iHp(iMaxHp)
		, iLevel(iLevel), iMaxExp(100), iExp(0), iGold(iGold)
	{
		strcpy_s(szName, 16, pName);
	}

}INFO;
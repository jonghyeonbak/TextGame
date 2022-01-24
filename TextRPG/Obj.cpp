#include "Obj.h"


CObj::CObj()
{
}

CObj::CObj(INFO& r_Info)
	:m_tInfo(r_Info)
{

}
CObj::~CObj()
{
}



int CObj::GetAtt()
{
	return m_tInfo.iAtt;
}

int CObj::GetHp()
{
	return m_tInfo.iHp;
}

void CObj::SetHp(int iAtt)
{
	m_tInfo.iHp += iAtt;
}

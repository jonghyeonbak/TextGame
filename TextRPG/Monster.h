#pragma once
#include "Obj.h"

class CMonster : public CObj
{
public:
	CMonster();
	CMonster(INFO& rInfo);
	virtual ~CMonster();

public:
	virtual void Initialize(void);
	virtual void Render(void);
	virtual void Release(void);


};


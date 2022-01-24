#pragma once
#include "Obj.h"

class CItem :
		public CObj
{
public:
	CItem();
	CItem(INFO& rInfo);
	virtual ~CItem();

public:
	virtual void Initialize() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	const TYPE& GetType() const { return m_eType; }
	const STATE& GetState() const { return m_eState; }
	const INFO& GetInfo() const { return m_tInfo; }
	
public:
	void SetType(TYPE eType) { m_eType = eType; }
	void SetState(STATE eState) { m_eState = eState; }

private:
	TYPE m_eType;
	STATE m_eState;
};


#pragma once
#include "Agent.h"

class Enemy : public Object
{
public:
	Enemy();
	virtual ~Enemy();
public:
	virtual void Update() abstract;
	virtual void Render(HDC _hdc) abstract;
	virtual void OnDie();
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
protected:
	int m_hp;
	int m_attack;
	Vec2 m_moveDesire;
};


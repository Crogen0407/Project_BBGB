#pragma once
#include "Object.h"
class Texture;
class Projectile : public Object
{
public:
	Projectile();
	~Projectile();
	void Update() override;
	void Render(HDC _hdc) override;
public:
	void SetDir(Vec2 _dir)
	{
		m_vDir = _dir;
		m_vDir.Normalize();
	}
	Vec2 GetDir()
	{
		return m_vDir;
	}
public:
	virtual void EnterCollision(Collider* _other);
	virtual void StayCollision(Collider* _other);
	virtual void ExitCollision(Collider* _other);
private:
	//float m_dir;
	Vec2 m_vDir;
	Texture* m_pTex;
	float speed = 500.f;
};


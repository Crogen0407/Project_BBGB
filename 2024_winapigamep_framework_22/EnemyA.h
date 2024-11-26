#pragma once
#include "Enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA();
	~EnemyA() override;
public:
	void Update() override; 
	void Render(HDC _hdc) override;
private:
	float shootDelay = 1;
	float prevShootTime = 0;
	Object* target;
private:
	float prevDash = 0;
};


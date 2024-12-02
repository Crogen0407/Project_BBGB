#pragma once
#include "Projectile.h"
class Texture;

class GuidedMissile : public Projectile
{
public:
	GuidedMissile();
	~GuidedMissile() override;
	void Update() override;
	void Render(HDC _hdc) override;
	void SetDir(Vec2 dir) override;
private:
	float _rotation = 0;
	float _lifetime = 3.f;
	float _spawnedTime = 0.f;

	Object* target;
};


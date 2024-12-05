#include "pch.h"
#include "ParrySparkEffect.h"
#include "ResourceManager.h"
#include "PoolManager.h"
#include "TimeManager.h"
#include "EventManager.h"
#include "Texture.h"
#include "Animator.h"

ParrySparkEffect::ParrySparkEffect()
{
	AddComponent<Animator>();
	SetSize({ 100,100 });
	Texture* texture = LOADTEXTURE(L"ParrySparkEffect", L"Texture\\Effect\\ParrySparkEffect.bmp");
	Vec2 texSize = { (int)texture->GetWidth() / 4, (int)texture->GetHeight() };
	_animator = GetComponent<Animator>();
	_animator->CreateAnimation(L"ParrySpark", texture, { 0,0 }, texSize, { (int)texSize.x,0 }, 4, 0.1f, false);

	_lifeTime = 0.15f;
}

ParrySparkEffect::~ParrySparkEffect()
{
}

void ParrySparkEffect::Update()
{
	_curTime += fDT;
	if (_curTime >= _lifeTime)
	{
		PUSH(L"ParrySparkEffect", this);
	}
}

void ParrySparkEffect::Render(HDC _hdc)
{
	ComponentRender(_hdc);
}

void ParrySparkEffect::OnPop()
{
	_animator->PlayAnimation(L"ParrySpark", true);
}

void ParrySparkEffect::OnPush()
{
	Effect::OnPush();
}
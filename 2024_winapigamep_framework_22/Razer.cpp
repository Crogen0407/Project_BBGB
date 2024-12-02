#include "pch.h"
#include "Razer.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "TimeManager.h"
#include "Texture.h"
#include "Collider.h"
#include "EventManager.h"

Razer::Razer(float lifeTime)
{
	SetSize({ 0,0 });
	_lifeTime = lifeTime;
	_texture = LOADTEXTURE(L"Razer", L"Texture\\Razer.bmp");

	AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(GetSize());
	_startLifeTime = TIME;
}

Razer::~Razer()
{
}

void Razer::Update()
{
	if (_startLifeTime + _lifeTime < TIME)
		GET_SINGLE(EventManager)->DeleteObject(this);

	//_dir.Normalize();
	//GetComponent<SpriteRenderer>()->LookAt({ 0,1 });
	Vec2 vPos = _owner->GetPos();
	Vec2 vSize = GetSize();

	if (vSize.y <= _targetSize)
		vSize = Vec2(100.f, vSize.y + (1000 * fDT));

	vPos = Vec2(vPos.x, vPos.y + 50 + vSize.y / 2);// Vec2(0, 1)* (vSize.y * 2);
	GetComponent<Collider>()->SetSize(vSize);
	SetSize(vSize);
	SetPos(vPos);
}

void Razer::Render(HDC _hdc)
{
	//ComponentRender(_hdc);
	Vec2 vPos = GetPos();
	Vec2 vSize = GetSize();

	int width = _texture->GetWidth();
	int height = _texture->GetHeight();
	::TransparentBlt(_hdc
		, (int)(vPos.x - vSize.x / 2)
		, (int)(vPos.y - vSize.y / 2)
		, vSize.x, vSize.y,
		_texture->GetTexDC()
		, 0, 0, width, height, RGB(255, 0, 255));
}

void Razer::EnterCollision(Collider* _other) { }
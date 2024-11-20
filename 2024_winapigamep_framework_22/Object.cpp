#include "pch.h"
#include "Object.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Component.h"

Object::Object()
	: m_vPos{}
	, m_vSize{}
	, m_IsDie(false)
{
	std::string str = typeid(this).name();
	wstring name;
	str.assign(name.begin(), name.end());
	SetName(name);
}

Object::~Object()
{
	for (Component* com : m_vecComponents)
	{
		if (com != nullptr)
			delete com;
	}
	m_vecComponents.clear();
}

void Object::LateUpdate()
{
	for (Component* com : m_vecComponents)
	{
		if (com)
		{
			com->LateUpdate();
		}
	}
}

void Object::ComponentRender(HDC _hdc)
{
	for (Component* com : m_vecComponents)
	{
		if (com)
		{
			com->Render(_hdc);
		}
	}
}

void Object::EnterCollision(Collider* _other)
{
}

void Object::StayCollision(Collider* _other)
{
}

void Object::ExitCollision(Collider* _other)
{
}

Object* Object::FindObject(std::wstring name, LAYER layer)
{
	vector<Object*> objects = GET_SINGLE(SceneManager)->GetCurrentScene()->GetLayerObjects(layer);

	for (Object* obj : objects)
	{
		if (obj->GetName() == name) {
			return obj;
		}
	}

	return nullptr;
}

//void Object::Update()
//{
//	if (GET_KEY(KEY_TYPE::LEFT))
//		m_vPos.x -= 100.f * fDT;
//	if (GET_KEY(KEY_TYPE::RIGHT))
//		m_vPos.x += 100.f * fDT;
//}
//
//void Object::Render(HDC _hdc)
//{
//	RECT_RENDER(_hdc, m_vPos.x, m_vPos.y
//		, m_vSize.x, m_vSize.y);
//}

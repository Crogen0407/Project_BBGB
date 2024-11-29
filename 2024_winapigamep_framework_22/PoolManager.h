#pragma once
#include <stack>
#include "SceneManager.h"
#include "Scene.h"

class PoolableObject;
class PoolManager
{
	DECLARE_SINGLE(PoolManager);
private:
	std::map<std::wstring, std::stack<PoolableObject*>> pool;
public:
	void Init();
	template<typename T>
	void MakeObjectPool(std::wstring key, LAYER layer, int count)
	{
		for (int i = 0; i < count; i++)
		{
			AddPool<T>(key, layer);
		}
	}
	template<typename T>
	void AddPool(std::wstring key, LAYER layer)
	{
		T* object = new T;
		object->name = key;
		GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(object, layer);
		pool[key].push(object);
		object->SetDead();
	}
public:
	PoolableObject* Pop(std::wstring type);
	void Push(PoolableObject* object);
};
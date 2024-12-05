#include "pch.h"
#include "BackgroundA.h"
#include "TimeManager.h"

BackgroundA::BackgroundA()
{
	_maxEnemyCount = 10;
	_spawnDelayTime = 20.f;
	_currentTime = _spawnDelayTime;
}

BackgroundA::~BackgroundA()
{
}

void BackgroundA::Update()
{
	_currentTime += fDT;
	if (_currentTime > _spawnDelayTime)
	{
		SpawnEnemyByRandomPos(EnemyType::EnemyA);
		_currentTime = 0.f;
	}
}

#include "pch.h"
#include "EnemySpawner.h"
#include "SceneManager.h"
#include "Enemy.h"
#include "EnemyA.h"
#include "EnemyB.h"
#include "EnemyC.h"
#include "Boss.h"
#include "Scene.h"

EnemySpawner::EnemySpawner()
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::SpawnEnemy(Vec2 pos, EnemyType enemyType)
{
	Enemy* enemy;

	switch (enemyType)
	{
	case EnemyType::EnemyA:
		enemy = new EnemyA();
		break;
	case EnemyType::EnemyB:
		enemy = new EnemyB();
		break;
	case EnemyType::EnemyC:
		enemy = new EnemyC();
		break;
	case EnemyType::Boss:
		enemy = new Boss();
		break;
	default:
		enemy = new EnemyA();
		break;
	}

	enemy->SetPos(pos);
	GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(enemy, LAYER::ENEMY);
}

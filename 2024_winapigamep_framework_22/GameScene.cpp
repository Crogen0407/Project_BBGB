#include "pch.h"
#include "GameScene.h"
#include "EnemyA.h"
#include "Player.h"

void GameScene::Init()
{
	Object* player = new Player;

	player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	player->SetSize({ 50, 50 });
	player->SetName(L"Player");
	AddObject(player, LAYER::PLAYER);

	Object* obj = new EnemyA;
	obj->SetPos({ rand() % SCREEN_WIDTH, rand() % SCREEN_HEIGHT });
	obj->SetSize({ 50, 50 });
	AddObject(obj, LAYER::ENEMY);

	/*for (size_t i = 0; i < 100; i++)
	{
	}*/
}
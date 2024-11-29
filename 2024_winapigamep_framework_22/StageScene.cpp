#include "pch.h"
#include "StageScene.h"
#include "CameraManager.h"
#include "StageManager.h"
#include "BackGround.h"
#include "EnemyA.h"
#include "Stage1.h"
#include "Stage2.h"
#include "Player.h"

void StageScene::Init()
{
    Object* player = new Player;

    player->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    player->SetName(L"Player");
    AddObject(player, LAYER::PLAYER);

    Object* enemy = new EnemyA;

    enemy->SetPos({ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
    enemy->SetName(L"Enemy");
    AddObject(enemy, LAYER::ENEMY);

    const int cellSizeX = 200;
    const int cellSizeY = 200;
    const int gridSize = 3;
    const int totalGridSize = cellSizeX * gridSize;

    const int startX = (SCREEN_WIDTH - totalGridSize) / 2 + 95;
    const int startY = (SCREEN_HEIGHT - totalGridSize) / 2 - 15;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            grid[i][j] = new BackGround;

            grid[i][j]->SetPos({ startX + i * cellSizeX, startY + j * cellSizeY });
            grid[i][j]->SetSize({ cellSizeX, cellSizeY });

            AddObject(grid[i][j], LAYER::BACKGROUND);
        }
    }
}

BackGround* StageScene::GetBackGroundAt(int x, int y)
{
    if (x >= 0 && x < gridSize && y >= 0 && y < gridSize)
    {
        return grid[x][y];
    }

    return nullptr;
}

#pragma once
#include "Stage.h"
class Stage2 :
    public Stage
{
public:
    virtual void Init() override;
    void Update();
    void Render(StageScene* stageScene, HDC _hdc);
public:     
    void DrawScene(StageScene* stageScene, int x, int y, HDC _hdc);
};
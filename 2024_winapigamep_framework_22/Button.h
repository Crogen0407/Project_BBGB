#pragma once
#include "Image.h"
class Texture;
class Button :
    public Image
{
public:
    Button();
    ~Button();
public:
    void Init(Texture* defultTex, Texture* selectedTex, Texture* pressedTex);
    void OnClick();
    void OnSelectEnter();
    void OnSelectExit();
public:
    void LateUpdate() override;
    void Render(HDC _hdc) override;
public:
    bool m_showDebug = false;
private:
    bool m_isSelected = false;
private:
    Texture* m_defaultTex;
    Texture* m_selectedTex;
    Texture* m_pressedTex;
};


#include "pch.h"
#include "Button.h"
#include "Texture.h"
#include "InputManager.h"
#include "GDISelector.h"
#include "ResourceManager.h"
#include "Canvas.h"

Button::Button() :
	m_defaultTex(nullptr),
	m_selectedTex(nullptr),
	m_pressedTex(nullptr)
	
{
}

Button::~Button()
{
}

void Button::Init(Texture* defultTex, Texture* selectedTex, Texture* pressedTex)
{
	m_defaultTex = defultTex;
	m_selectedTex = selectedTex;
	m_pressedTex = pressedTex;
}

void Button::OnClick()
{
	if(m_pressedTex != nullptr)
		texture = m_pressedTex;
	OnClickEvent.Invoke(NULL);
}

void Button::OnSelectEnter()
{
	if (m_selectedTex != nullptr)
		texture = m_selectedTex;
	OnSelectEnterEvent.Invoke(NULL);
}

void Button::OnSelectExit()
{
	if (m_defaultTex != nullptr)
		texture = m_defaultTex;
	OnSelectExitEvent.Invoke(NULL);
}

void Button::LateUpdate()
{
	Vec2 pos = GetPos() + owner->GetPos();
	Vec2 size = GetSize();

	Vec2 mousePos = GET_MOUSEPOS;

	if (pos.y + (size.y / 2) > mousePos.y &&
		pos.x + (size.x / 2) > mousePos.x &&
		pos.y - (size.y / 2) < mousePos.y &&
		pos.x - (size.x / 2) < mousePos.x) //마우스가 닿았는지
	{
		if (m_isSelected == false)
		{
			m_isSelected = true;
			OnSelectEnter();
		}
		if (GET_KEYDOWN(KEY_TYPE::LBUTTON) || GET_KEYDOWN(KEY_TYPE::RBUTTON))
		{
			OnClick();
		}
	}
	else
	{
		if (m_isSelected == true)
		{
			m_isSelected = false;
			OnSelectExit();
		}
	}
}

void Button::Render(HDC _hdc)
{
	Image::Render(_hdc);

	Vec2 pos = GetPos();
	Vec2 size = GetSize();

	if (m_showDebug)
	{
		PEN_TYPE ePen = PEN_TYPE::RED;
		GDISelector pen(_hdc, ePen);
		GDISelector brush(_hdc, BRUSH_TYPE::HOLLOW);
		RECT_RENDER(_hdc, pos.x, pos.y,
			size.x, size.y);
	}
}
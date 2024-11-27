#pragma once
#include "Component.h"
#include "Action.h"
class HealthCompo :
    public Component
{
public:
    HealthCompo();
    ~HealthCompo() override;
public:
    Action<float> ChangeHpEvent;
    Action<int> DieEvent;
public:
    void SetOffsetY(float value)
    {
        offsetY = value;
    }
    const void SetHpBarActive(bool active)
    {
        hpBarActive = active;
    }
    void SetHp(float hp)
    {
        this->hp = hp;
        ChangeHpEvent.Invoke(hp/maxHp);
    }
    void SetHp(float hp, float maxHp)
    {
        this->maxHp = maxHp;
        SetHp(hp);
    }
    virtual void ApplyDamage(int value);
    void ApplyHeal(int value);
    void OnDie()
    {
        DieEvent.Invoke(NULL);
    }
    const float GetHp() const
    {
        return hp;
    }
public:
    virtual void LateUpdate() override;
    void Render(HDC hdc) override;
private:
    //HpBar
    HBRUSH fillBrush;
    HBRUSH backBrush;
protected:
    bool hpBarActive = true;
    float offsetY = 0;
    float hp;
    float maxHp;
};


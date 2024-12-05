#pragma once
#include "HealthCompo.h"
class CameraManager;
class PlayerHealthCompo :
    public HealthCompo
{
public:
    PlayerHealthCompo();
    ~PlayerHealthCompo() override;
public:
    Action<float> ChangeSubHpEvent;
public:
    void SetSubHp(float subHp)
    {
        this->subHp = std::clamp(subHp, 0.f, maxSubHp);
        ChangeSubHpEvent.Invoke(subHp / maxSubHp);
    }
    void SetSubHp(float subHp, float maxSubHp)
    {
        this->maxSubHp = maxSubHp;
        SetHp(subHp);
    }
    const float GetSubHp() const
    {
        return subHp;
    }
    void SetAutoCureValue(float value)
    {
        autoCureValue = value;
    }
    const float GetAutoCureValue() const 
    {
        return autoCureValue;
    }
    void ApplyDamage(int value) override;
    void OnDie() override;

public:
    void LateUpdate() override;
private:
    bool _isDie = false;
    float curDelay = 0;
    bool isTakedDamage = false;
    float subHp;
    float maxSubHp;
    float autoCureValue = 5.f;
    CameraManager* cameraShake;
};


#pragma once
#include "component.h"

class Attack : Component
{
    bool isAttacking;
    float nrAttacks;
    float speed;
    float timer;
    float range;
    int weapon;
};
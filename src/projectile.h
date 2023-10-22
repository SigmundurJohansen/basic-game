#pragma once
#include "core/components.h"
#include <entt/entt.hpp>
#include <string>

class Projectile
{
    Projectile(Avarice::transform_component _origin, Avarice::transform_component _target);
    Avarice::game_object_component m_gameObject;
    Avarice::transform_component m_transform;
    Avarice::pathfinding_component m_path;
    Avarice::projectile_component m_projectile;
};
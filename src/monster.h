#pragma once
#include "core/components.h"
#include <entt/entt.hpp>
#include <string>

class Monster
{
  public:
    Monster(std::string _name, int _x, int _y);
    Avarice::game_object_component m_gameObject;
    Avarice::faction_component m_faction;
    Avarice::transform_component m_transform;
    Avarice::pathfinding_component m_path;
};
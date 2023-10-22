#pragma once
#include "core/components.h"
#include <entt/entt.hpp>

class Tower
{
  public:
    Tower(std::string _name, int _x, int _y);
    Avarice::game_object_component m_gameObject;
    Avarice::transform_component m_transform;
    Avarice::faction_component m_faction;
};
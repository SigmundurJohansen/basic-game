#include "tower.h"
#include "components.h"
#include "service_locator.h"

Tower::Tower(std::string _name, int _x, int _y)
{
    float white[4] = {1, 1, 1, 1};
    entt::entity tower = Avarice::ServiceLocator::GetEntites()->GetRegistry().create();

    m_gameObject.name = "enemy";
    m_gameObject.type = 3;
    m_gameObject.range = 200.0f;
    m_gameObject.health = 10;
    m_gameObject.damage = 10;
    m_gameObject.rate_of_fire = 2.0f;
    m_gameObject.timer = 0.0f;
    m_gameObject.health = 100;
    auto tower_position = glm::vec3(_x, _y, 0.0f);
    auto tower_scale = glm::vec3(0.1f, 0.1f, 1.0f);

    m_transform.position = tower_position;
    m_transform.scale = tower_scale;
    m_transform.velocity = glm::vec3{0, 0, 0};
    m_transform.mass = 1.0f;
    m_transform.depth = 0.4f;
    m_transform.rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    m_gameObject.model = _name;
    m_faction.id = 1;

    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::alive_component>(tower);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::faction_component>(tower, m_faction);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::game_object_component>(tower, m_gameObject);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::transform_component>(tower, m_transform);
}
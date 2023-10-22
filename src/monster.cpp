#include "monster.h"
#include "components.h"
#include "game_manager.h"
#include "service_locator.h"

std::vector<glm::vec3> waypoints_map1 = {
    glm::vec3(902, 452, 0), glm::vec3(851, 472, 0),
    glm::vec3(751, 427, 0), glm::vec3(956, 324, 0),
    glm::vec3(839, 272, 0), glm::vec3(451, 474, 0),
    glm::vec3(389, 440, 0), glm::vec3(349, 477, 0),
    glm::vec3(237, 424, 0), glm::vec3(714, 192, 0),
    glm::vec3(590, 140, 0), glm::vec3(501, 202, 0),
    glm::vec3(447, 171, 0), glm::vec3(298, 257, 0),
    glm::vec3(200, 190, 0)};

Monster::Monster(std::string _name, int _x, int _y)
{
    float white[4] = {1, 1, 1, 1};
    entt::entity monster = Avarice::ServiceLocator::GetEntites()->GetRegistry().create();
    auto & gm = Avarice::GameManager::GetInstance();
    int my_id = gm.GetGlobalInteger7()+ 1; 
    gm.SetGlobalInteger7(my_id);
    m_gameObject.name = "player";
    m_gameObject.type = 3;
    m_gameObject.health = 100;
    m_gameObject.id = my_id;
    m_gameObject.model = _name;
    
    auto monster_position = glm::vec3(_x, _y, 0.0f);
    auto monster_scale = glm::vec3(0.07f, 0.07f, 1.0f);

    m_path.targetPosition = glm::vec3(899, 445, 1.0f);
    m_path.waypoints = waypoints_map1;
    m_path.speed = 63.5f;
    m_path.state = Avarice::moving;
    m_path.currentStepIndex = 0;

    m_transform.position = monster_position;
    m_transform.scale = monster_scale;
    m_transform.velocity = glm::vec3{0, 0, 0};
    m_transform.mass = 1.0f;
    m_transform.depth = 0.3f;
    m_transform.rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    m_faction.id = 2;

    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::alive_component>(monster);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::faction_component>(monster, m_faction);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::pathfinding_component>(monster, m_path);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::game_object_component>(monster, m_gameObject);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::transform_component>(monster, m_transform);
}
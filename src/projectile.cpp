#include "projectile.h"
#include "service_locator.h"

Projectile::Projectile(Avarice::transform_component _origin, Avarice::transform_component _target)
{
    entt::entity projectile_entity = Avarice::ServiceLocator::GetEntites()->GetRegistry().create();

    Avarice::game_object_component gameObject;
    gameObject.name = "projectile";
    gameObject.type = 3;
    Avarice::projectile_component projectile;
    projectile.speed = 24.2f;
    // projectile.target = _target.position;
    auto projectile_position = glm::vec3(-5.0f, 2.0f, -5.0f) + _origin.position;
    auto projectile_scale = glm::vec3(0.1f, 0.1f, 0.1f);
    auto projectile_mass = 0.1f;

    Avarice::transform_component projectile_transform;
    projectile_transform.position = projectile_position;
    projectile_transform.scale = projectile_scale;
    projectile_transform.mass = projectile_mass;
    projectile_transform.depth = 0.5;
    projectile_transform.rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    float white[4] = {1, 1, 1, 1};
    gameObject.model = "arrow01";
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::projectile_component>(projectile_entity, projectile);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::game_object_component>(projectile_entity, gameObject);
    Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::transform_component>(projectile_entity, projectile_transform);
}
#include "../AvariceEngine/entrypoint.h"
#include "GLFW/glfw3.h"
#include "components.h"
#include "game.h"
#include "game_manager.h"
#include "imgui.h"
#include "logger.h"
#include "maps.h"
#include "monster.h"
#include "platform/custom_window.h"
#include "resource_manager.h"
#include "service_locator.h"
#include "settings.h"
#include "utils/time.h"
#include <thread>

using namespace Avarice;

const std::string asset_directory = "D:/repo/basic-game/assets/textures/demo";

// colors
float white[4] = {1, 1, 1, 1};

struct coordinates
{
    int x;
    int y;
};

class SuperGame : public Game
{
  public:
    GameSettings settings;
    game_map start_map;

    explicit SuperGame(std::string _title) : Game(std::move(_title))
    {

        float white[4] = {1, 1, 1, 1};
        settings.SetGameSettings();
        ResourceManager::LoadTextures(asset_directory);
        auto &game_manager = GameManager::GetInstance();
        game_manager.SetGlobalString1("isometric_0000");
        game_manager.SetGlobalBool1(false);
        game_manager.SetGlobalBool2(true);
        game_manager.SetGlobalInteger1(100); // health
        game_manager.SetGlobalInteger2(500); // money
        game_manager.SetGlobalInteger3(0);   // turn
        // Tower Prices
        game_manager.SetGlobalInteger4(100); // tower 1
        game_manager.SetGlobalInteger5(300); // tower 2
        int i = 0;
        float depth = 0.0001f;
        for (int y = 0; y < 20; y++)
        {
            for (int x = 0; x < 10; x++)
            {
                int my_id = game_manager.GetGlobalInteger7() + 1;
                game_manager.SetGlobalInteger7(my_id);

                entt::entity tile = Avarice::ServiceLocator::GetEntites()->GetRegistry().create();
                game_object_component tile_object;
                tile_object.name = "tile";
                tile_object.type = 2;
                tile_object.health = 100;
                tile_object.id = my_id;
                if (game_map1.size() > i)
                    tile_object.model = game_map1[i];
                Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::game_object_component>(tile, tile_object);

                transform_component tile_transform;
                tile_transform.position.x = 200 * x + y % 2 * 100 + 100;
                tile_transform.position.y = 50 * y + 100;
                tile_transform.scale = glm::vec3(0.2);
                tile_transform.depth = depth;
                depth = depth + 0.0001f;
                Avarice::ServiceLocator::GetEntites()->GetRegistry().emplace<Avarice::transform_component>(tile, tile_transform);
                i++;
            }
        }
        ServiceLocator::GetRenderer()->AddImage(200, 190, altar[0], 0.08, 0.2);
        ServiceLocator::GetRenderer()->AddImage(1000, 490, fire[0], 0.08, 0.2);

        s_monsters.emplace_back(Monster("skeleton1", 990, 480));
    }

  protected:
    virtual void Update(float _deltaTime) override
    {
        auto &game_manager = GameManager::GetInstance();
        ServiceLocator::GetEntites()->Update(_deltaTime);
        game_manager.SetGlobalInteger3(glfwGetTime());
        if (game_manager.GetGlobalInteger3() == 5 && game_manager.GetGlobalBool2())
        {
            s_monsters.emplace_back(Monster("skeleton1", 990, 480));
            game_manager.SetGlobalBool2(false);
            game_manager.SetGlobalBool3(true);
        }
        if (game_manager.GetGlobalInteger3() == 6 && game_manager.GetGlobalBool3())
        {
            s_monsters.emplace_back(Monster("skeleton1", 990, 480));
            game_manager.SetGlobalBool3(false);
            game_manager.SetGlobalBool4(true);
        }
        if (game_manager.GetGlobalInteger3() == 7 && game_manager.GetGlobalBool4())
        {
            s_monsters.emplace_back(Monster("skeleton4", 990, 480));
            game_manager.SetGlobalBool4(false);
            game_manager.SetGlobalBool5(true);
        }
        if (game_manager.GetGlobalInteger3() == 8 && game_manager.GetGlobalBool5())
        {
            s_monsters.emplace_back(Monster("skeleton2", 990, 480));
            game_manager.SetGlobalBool5(false);
            game_manager.SetGlobalBool4(true);
        }
        if (game_manager.GetGlobalInteger3() == 9 && game_manager.GetGlobalBool6())
        {
            s_monsters.emplace_back(Monster("skeleton3", 990, 480));
            game_manager.SetGlobalBool6(false);
        }
    }
};

Game *Avarice::CreateGame()
{
    return new SuperGame("main game");
}
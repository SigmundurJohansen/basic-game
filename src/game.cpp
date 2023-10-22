#include "game.h"
#include "GLFW/glfw3.h"
#include "components.h"
#include "game_manager.h"
#include "logger.h"
#include <thread>

void game_map::Loop()
{
    auto &game_manager = Avarice::GameManager::GetInstance();
    auto &logger = Avarice::AvariceLogger::GetInstance();

    auto startTime = std::chrono::high_resolution_clock::now();
    logger.Debug("gamemap", "starting loop");
    if (stage == 0)
    {
        stage++;
        logger.Debug("gamemap", "starting stage %d", stage);
    }
    if (stage == 1)
    {
        stage++;
        logger.Debug("gamemap", "starting stage %d", stage);
        if (s_monsters.empty() || spawned < wave2)
        {
            for (int i = 0; i < wave1; i++)
            {
                auto currentTime = std::chrono::high_resolution_clock::now();
                double elapsedSeconds = std::chrono::duration<double>(currentTime - startTime).count();
                if (elapsedSeconds >= delayInSeconds)
                {
                    s_monsters.emplace_back(Monster("skeleton1", start_x, start_y));
                    spawned++;
                }
            }
        }
    }
    else
        logger.Debug("gamemap", "game over");
    prev_time = timer;
}

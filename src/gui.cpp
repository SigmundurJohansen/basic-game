#include "gui.h"
#include "game.h"
#include "game_manager.h"
#include "service_locator.h"
#include "tower.h"
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>
#include <imgui/imgui.h>
#include <imgui_internal.h>
#include <iostream>


void GUI::left_click()
{
    Avarice::ServiceLocator::GetCamera()->IntersectRayBox();
    double x, y, z;
    Avarice::ServiceLocator::GetWindow()->RequestMousePos(&x, &y);
    float white[4] = {1, 1, 1, 1};
    auto &gm = Avarice::GameManager::GetInstance();
    if (gm.GetGlobalBool1())
    {
        int cost = 999999;
        if (gm.GetGlobalString1().find("tower01") != std::string::npos)
            cost = gm.GetGlobalInteger4();
        if (gm.GetGlobalString1().find("tower02") != std::string::npos)
            cost = gm.GetGlobalInteger5();
        if (gm.GetGlobalInteger2() >= cost)
        {
            s_towers.emplace_back(Tower(gm.GetGlobalString1(), x, y));
            gm.SetGlobalInteger2(gm.GetGlobalInteger2()-cost);
        }
    }
    std::cout << "x: " << x << " y: " << y << std::endl;
}
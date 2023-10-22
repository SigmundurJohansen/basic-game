#pragma once
#include "include/inputs/input_manager.h"
#include "service_locator.h"

class GameSettings
{
  public:
    GameSettings() = default;
    Avarice::InputManager *m_inputManager;
    int SetGameSettings();
};
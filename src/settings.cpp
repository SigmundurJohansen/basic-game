#include "settings.h"
#include "game_manager.h"
#include "gui.h"
#include "logger.h"
#include "service_locator.h"
#include <iostream>


using namespace Avarice;

int GameSettings::SetGameSettings()
{
    auto &logger = AvariceLogger::GetInstance();

    m_inputManager = ServiceLocator::GetInputManager();
    if (m_inputManager)
    {
        logger.Debug("Test", "configuring input manager");
        m_inputManager->MapInputToAction(InputKey::MOUSE_LEFT, InputAction{.actionName = "left_click"});
        m_inputManager->MapInputToAction(InputKey::MOUSE_RIGHT, InputAction{.actionName = "click"});
        m_inputManager->MapInputToAction(InputKey::KEY_W, InputAction{.actionName = "forward"});
        m_inputManager->MapInputToAction(InputKey::KEY_A, InputAction{.actionName = "left"});
        m_inputManager->MapInputToAction(InputKey::KEY_S, InputAction{.actionName = "back"});
        m_inputManager->MapInputToAction(InputKey::KEY_D, InputAction{.actionName = "right"});
        m_inputManager->MapInputToAction(InputKey::KEY_C, InputAction{.actionName = "down"});
        m_inputManager->MapInputToAction(InputKey::SPACE, InputAction{.actionName = "up"});

        m_inputManager->RegisterActionCallback("left", InputManager::ActionCallback{.Ref = "main game",
                                                                                    .Func = [](InputSource source, int sourceIndex, float value) {
                                                                                        auto &logger = AvariceLogger::GetInstance();
                                                                                        logger.Debug("input", "moving left");
                                                                                        ServiceLocator::GetCamera()->MoveLeft(9991);
                                                                                        return true;
                                                                                    }});

        m_inputManager->RegisterActionCallback("right", InputManager::ActionCallback{.Ref = "main game",
                                                                                     .Func = [](InputSource source, int sourceIndex, float value) {  
                                                                                        auto &logger = AvariceLogger::GetInstance();
                                                                                        logger.Debug("input", "moving right");
                                                                                        ServiceLocator::GetCamera()->MoveRight(51);
                                                                                         return true;
                                                                                     }});

        m_inputManager->RegisterActionCallback("back", InputManager::ActionCallback{.Ref = "main game",
                                                                                    .Func = [](InputSource source, int sourceIndex, float value) {
                                                                                        return true;
                                                                                    }});

        m_inputManager->RegisterActionCallback("forward", InputManager::ActionCallback{.Ref = "main game",
                                                                                       .Func = [](InputSource source, int sourceIndex, float value) {
                                                                                           return true;
                                                                                       }});

        m_inputManager->RegisterActionCallback("down", InputManager::ActionCallback{.Ref = "main game",
                                                                                    .Func = [](InputSource source, int sourceIndex, float value) {
                                                                                        return true;
                                                                                    }});
        m_inputManager->RegisterActionCallback("up", InputManager::ActionCallback{.Ref = "main game",
                                                                                  .Func = [](InputSource source, int sourceIndex, float value) {
                                                                                      return true;
                                                                                  }});
        m_inputManager->RegisterActionCallback("left_click", InputManager::ActionCallback{.Ref = "main game",
                                                                                          .Func = [this](InputSource source, int sourceIndex, float value) {
                                                                                              if (value == 0)
                                                                                                  GUI::left_click();
                                                                                              return true;
                                                                                          }});
        m_inputManager->RegisterActionCallback("click", InputManager::ActionCallback{.Ref = "main game",
                                                                                     .Func = [this](InputSource source, int sourceIndex, float value) {
                                                                                         if (value == 0)
                                                                                             ServiceLocator::GetCamera()->ToggleFirstMouseClick();

                                                                                         ServiceLocator::GetWindow()->SetCursorVisibility(false);
                                                                                         if (value == 0)
                                                                                             ServiceLocator::GetWindow()->SetCursorVisibility(true);
                                                                                         return true;
                                                                                     }});
    }
    return 0;
}
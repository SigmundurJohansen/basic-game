#include <iostream>
#include "monster.h"
#include "humanoid.h"
#include <../engine/entrypoint.h>
#include <coroutine>

using namespace Avarice;

class SuperGame : public Game
{
public:
    Humanoid all_humans[100];
    InputManager *m_inputManager;
    static inline bool m_orientate;
    static inline bool m_moveUp;
    static inline bool m_moveLeft;
    static inline bool m_moveRight;
    static inline bool m_moveDown;
    static inline bool m_moveForward;
    static inline bool m_moveBackward;

    static void ToggleOrientate(){ m_orientate ? m_orientate = false : m_orientate = true;}
    static void ToggleMoveUp(){ m_moveUp ? m_moveUp = false : m_moveUp = true;}
    static void ToggleMoveLeft(){ m_moveLeft ? m_moveLeft = false : m_moveLeft = true;}
    static void ToggleMoveRight(){ m_moveRight ? m_moveRight = false : m_moveRight = true;}
    static void ToggleMoveDown(){ m_moveDown ? m_moveDown = false : m_moveDown = true;}
    static void ToggleMoveForward(){ m_moveForward ? m_moveForward = false : m_moveForward = true;}
    static void ToggleMoveBack(){ m_moveBackward ? m_moveBackward = false : m_moveBackward = true;}

    void SetGameSettings()
    {
        m_moveUp = false;
        m_inputManager = ServiceLocator::GetInputManager();
        if(m_inputManager)
        {
            std::cout << "setting input manager \n";
            m_inputManager->MapInputToAction(InputKey::MOUSE_LEFT, InputAction{ .actionName = "click" });
            m_inputManager->MapInputToAction(InputKey::KEY_W, InputAction{ .actionName = "forward" });
            m_inputManager->MapInputToAction(InputKey::KEY_A, InputAction{ .actionName = "left" });
            m_inputManager->MapInputToAction(InputKey::KEY_S, InputAction{ .actionName = "back" });
            m_inputManager->MapInputToAction(InputKey::KEY_D, InputAction{ .actionName = "right" });
            m_inputManager->MapInputToAction(InputKey::KEY_C, InputAction{ .actionName = "down" });
            m_inputManager->MapInputToAction(InputKey::SPACE, InputAction{ .actionName = "up" });

            m_inputManager->RegisterActionCallback("left", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "left";
                ToggleMoveLeft();
                return true;
            }
            });

            m_inputManager->RegisterActionCallback("right", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "right";
                ToggleMoveRight();
                return true;
            }
            });

            m_inputManager->RegisterActionCallback("back", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "backingup";
                ToggleMoveBack();
                return true;
            }
            });

            m_inputManager->RegisterActionCallback("forward", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                ToggleMoveForward();
                return true;
            }
            });

            m_inputManager->RegisterActionCallback("down", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "down";
                ToggleMoveDown();
                return true;
            }
            });
            m_inputManager->RegisterActionCallback("up", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [] (InputSource source, int sourceIndex, float value)
            {
                ToggleMoveUp();
                return true;
            }
            });
            m_inputManager->RegisterActionCallback("click", InputManager::ActionCallback { 
                .Ref = "main game",
                .Func = [this] (InputSource source, int sourceIndex, float value)
            {
                std::cout << "clicking";
                if(value == 0)                
                    ServiceLocator::GetCamera()->ToggleFirstMouseClick();
                
                ServiceLocator::GetWindow()->SetCursorVisibility(false);
                ToggleOrientate();
                if(value == 0)
                    ServiceLocator::GetWindow()->SetCursorVisibility(true);
                return true;
            }
            });
        }
    }

    explicit SuperGame(std::string _title) : Game(std::move(_title))
    {
        SetGameSettings();
        all_humans[0].m_name = "billy";
        all_humans[0].PrintStat();
        all_humans[1].PrintStat();
        Item longswordPlussOne;
        longswordPlussOne.m_name = "longsword +1";
        longswordPlussOne.AddEnchantment(ItemEnchantment(damage, 1));
        longswordPlussOne.AddEnchantment(ItemEnchantment(thac0, 1));
        all_humans[0].m_inventory[6] = longswordPlussOne;
        std::cout << "equpied weapon: ";
        all_humans[0].m_inventory[6].PrintStats();
        Monster one("goblin");
        std::cout << one.GetName() << std::endl;
    }

protected:
    virtual void Update(float _deltaTime) override
    {
        if(m_orientate)
        {
            ServiceLocator::GetCamera()->Orientate(_deltaTime);
        }
        if(m_moveUp)
            ServiceLocator::GetCamera()->MoveUp(_deltaTime);
        if(m_moveDown)
            ServiceLocator::GetCamera()->MoveDown(_deltaTime);
        if(m_moveLeft)
            ServiceLocator::GetCamera()->MoveLeft(_deltaTime);
        if(m_moveRight)
            ServiceLocator::GetCamera()->MoveRight(_deltaTime);
        if(m_moveForward)
            ServiceLocator::GetCamera()->MoveForward(_deltaTime);
        if(m_moveBackward)
            ServiceLocator::GetCamera()->MoveBackwards(_deltaTime);

            
        //std::cout << "i'm updating" << std::endl;
    }
};

Game *Avarice::CreateGame()
{
    return new SuperGame("main game");
}
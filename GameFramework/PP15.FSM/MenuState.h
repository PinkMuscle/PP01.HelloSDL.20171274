#ifndef MenuState_h
#define MenuState_h
#include "GameState.h"

class MenuState : public GameState
{
public:
    ~MenuState() {}
    static MenuState* Instance()
    {
        if (pInstance == nullptr)
        {
            pInstance = new MenuState();
        }
        return pInstance;
    }
    virtual void Update();
    virtual void Render();
    virtual bool OnEnter();
    virtual bool OnExit();
    virtual std::string GetStateID() const { return menuID; }
private:
    MenuState() {}
    static MenuState* pInstance;
    static const std::string menuID;
};

#endif
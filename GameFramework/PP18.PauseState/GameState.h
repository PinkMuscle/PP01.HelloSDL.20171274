#ifndef GameState_h
#define GameState_h
#include <string>
#include <vector>
#include "GameObject.h"

class GameState
{
public:
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual bool OnEnter() = 0;
    virtual bool OnExit() = 0;
    virtual std::string GetStateID() const = 0;
protected:
    std::vector<GameObject*> gameObjects;
};

#endif
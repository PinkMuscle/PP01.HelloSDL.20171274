#ifndef Animal_h
#define Animal_h
#include "SDLGameObject.h"

enum animal_state
{
    FREE = 0,
    HUNTED = 1
};

class Enemy;

class Animal : public SDLGameObject
{
public:
    Animal(const LoaderParams& pParams);
    virtual void Draw();
    virtual void Update();
    virtual void Clean();
    virtual void Destroy();
    void HuntedBy(Enemy* enemy_);
    animal_state GetState() const { return state; }

private:
    Enemy* enemy;
    animal_state state;
};

#endif
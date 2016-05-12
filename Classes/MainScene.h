#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

class Character;
#include "Obstacle.hpp"

enum class State{
    Ready,
    Playing,
    GameOver,
};

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void onEnter() override;
    void update(float dt) override;

    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
protected:
    Character* character;
    cocos2d::Vector<Obstacle*> obstacles;
    cocos2d::Node* background;
    State gameState;
    cocos2d::Node* ground1;
    cocos2d::Node* ground2;
    
    void setupTouchHandling();
    void createObstacle(float dt);
    
    void triggerPlaying();
    void triggerGameOver();
    void triggerReady();

};

#endif // __MainScene_SCENE_H__

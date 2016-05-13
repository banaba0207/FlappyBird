#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

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
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    
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
    cocos2d::ui::TextBMFont* scoreLabel;
    int score;
    
    void setupTouchHandling();
    void createObstacle(float dt);
    
    void triggerPlaying();
    void triggerGameOver();
    void triggerReady();
    void setScore(int score);
};

#endif // __MainScene_SCENE_H__

#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "CharacterReader.hpp"
#include "Character.hpp"
#include "Obstacle.hpp"
#include "ObstacleReader.hpp"
#include "Constants.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    CSLoader* instance = CSLoader::getInstance();
    instance->registReaderObject("CharacterReader", (ObjectFactory::Instance) CharacterReader::getInstance);
    instance->registReaderObject("ObstacleReader", (ObjectFactory::Instance) ObstacleReader::getInstance);
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    
    Size size = Director::getInstance()->getVisibleSize();
    rootNode->setContentSize(size);
    ui::Helper::doLayout(rootNode);
    
    this->background= rootNode->getChildByName("back");
    this->character = this->background->getChildByName<Character*>("character");
    
    
    this->ground1 = this->background->getChildByName("ground1");
    this->ground2 = this->background->getChildByName("ground2");
    this->ground1->setLocalZOrder(1);
    this->ground2->setLocalZOrder(2);
    
    this->character->setLocalZOrder(3);
    addChild(rootNode);
    
    return true;
}

void MainScene::onEnter()
{
    Layer::onEnter();
    this->setupTouchHandling();
    this->scheduleUpdate();
    
}

void MainScene::update(float dt)
{
    if (this->gameState == State::Playing)
    {
        //障害物の移動
        for(auto obstacle : this->obstacles)
        {
            obstacle->moveLeft(SCROLL_SPEED * dt);
        }
        
        //床の移動
        this->ground1->setPosition(this->ground1->getPosition() + Vec2(- SCROLL_SPEED * dt, 0));
        if (this->ground1->getPosition().x < -288)
        {
            this->ground1->setPosition(Vec2(288, 110));
        }
        this->ground2->setPosition(this->ground2->getPosition() + Vec2(- SCROLL_SPEED * dt, 0));
        if (this->ground2->getPosition().x < -288)
        {
            this->ground2->setPosition(Vec2(288, 110));
        }
        
        //障害物とキャラの当たり判定
        Rect characterRect = this->character->getRect();
        for(auto obstacle : this->obstacles)
        {
            auto obstacleRects = obstacle->getRects();
            for (Rect obstacleRect : obstacleRects)
            {
                if(characterRect.intersectsRect(obstacleRect))
                {
                    this->triggerGameOver();
                }
                else{
                    CCLOG("");
                }
            }
        }
        
    }
    //床とキャラの当たり判定（厳密には判定していない）
    if(this->character->getPosition().y <= 110.0f + this->character->getChildByName("bird")->getContentSize().height)
    {
        this->triggerGameOver();
        this->character->stopFly();
    }
}


void MainScene::setupTouchHandling()
{
    auto touchListener = EventListenerTouchOneByOne::create();
    
    touchListener->onTouchBegan = [&](Touch* touch, Event* event)
    {
        switch (this->gameState)
        {
            case State::Ready:
                this->triggerPlaying();
                break;
            case State::Playing:
                this->character->jump();
                break;
            case State::GameOver:
                auto nextGameScene = MainScene::createScene();
                auto transition = TransitionFade::create(1.0f, nextGameScene);
                Director::getInstance()->replaceScene(transition);
                break;
        }
        return true;
    };
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

void MainScene::createObstacle(float dt)
{
    Obstacle* obstacle = dynamic_cast<Obstacle*>(CSLoader::createNode("Obstacle.csb"));
    this->obstacles.pushBack(obstacle);
    this->background->addChild(obstacle);
    float y = CCRANDOM_0_1() * (OBSTACLE_MAX_Y - OBSTACLE_MIN_Y) + OBSTACLE_MIN_Y;
    obstacle->setPosition(Vec2(OBSTACLE_INIT_X, y));
    
    if (this->obstacles.size() > OBSTACLE_LIMIT)
    {
        this->obstacles.front()->removeFromParent();
        this->obstacles.erase(this->obstacles.begin());
    }
}

void MainScene::triggerReady()
{
    this->gameState = State::Ready;
    this->character->stopFly();
}


void MainScene::triggerPlaying()
{
    this->gameState = State::Playing;
    this->character->startFly();
    this->schedule(CC_SCHEDULE_SELECTOR(MainScene::createObstacle), OBSTACLE_TIME_SPAN);
}

void MainScene::triggerGameOver()
{
    this->gameState = State::GameOver;
    this->unschedule(CC_SCHEDULE_SELECTOR(MainScene::createObstacle));
}
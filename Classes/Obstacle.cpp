#include "Obstacle.hpp"

using namespace cocos2d;

bool Obstacle::init()
{
    if (! Node::init())
    {
        return false;
    }
    
    this->timeline = cocos2d::CSLoader::createTimeline("Obstacle.csb");
    this->timeline->retain();
    
    return true;
}

void Obstacle::moveLeft(float distance)
{
    this->setPosition(this->getPosition() + Vec2(-distance, 0));
}
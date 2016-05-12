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

std::vector<cocos2d::Rect> Obstacle::getRects()
{
    std::vector<cocos2d::Rect> rects;
    auto contentPos = this->getPosition();
    auto pipeTop = this->getChildByName<Sprite*>("pipe_top");
    auto pipeBottom = this->getChildByName<Sprite*>("pipe_bottom");
    
    auto pipeTopRect = pipeTop->getBoundingBox();
    auto pipeBottomRect = pipeBottom->getBoundingBox();
    pipeTopRect.origin += this->getPosition();
    pipeBottomRect.origin += this->getPosition();

    rects.push_back(pipeTopRect);
    rects.push_back(pipeBottomRect);
    //
//    rects.push_back(Rect(contentPos.x - 50, contentPos.y +  50, 52, 320));
//    rects.push_back(Rect(contentPos.x - 50, contentPos.y - 370, 52, 320));
    
    return rects;
}
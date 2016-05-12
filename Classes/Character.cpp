//
//  Character.cpp
//  SushiNeko
//
//  Created by Takuro Yamaguchi on 2016/04/26.
//
//

#include "Character.hpp"
#include "Constants.h"
using namespace cocos2d;

bool Character::init()
{
    if (! Node::init())
    {
        return false;
    }

    this->timeline = cocos2d::CSLoader::createTimeline("Character.csb");
    this->timeline->retain();
    this->velocity = 0;
    this->accel = GRAVITY_ACCEL;
    return true;
}

void Character::onEnter()
{
    Node::onEnter();
    this->scheduleUpdate();
}

void Character::update(float dt)
{
    this->velocity += accel * dt;
    this->setPosition(this->getPosition() + Vec2(0, this->velocity * dt));
}

void Character::jump()
{
    this->velocity = JUMP_SPEED;
}
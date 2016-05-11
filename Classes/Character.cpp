//
//  Character.cpp
//  SushiNeko
//
//  Created by Takuro Yamaguchi on 2016/04/26.
//
//

#include "Character.hpp"

bool Character::init()
{
    if (! Node::init())
    {
        return false;
    }

    this->timeline = cocos2d::CSLoader::createTimeline("Character.csb");
    this->timeline->retain();
    
    return true;
}
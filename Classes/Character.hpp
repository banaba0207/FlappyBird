#ifndef __SushiNeko__Character__
#define __SushiNeko__Character__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"


class Character : public cocos2d::Node
{
public:
    CREATE_FUNC(Character);
    bool init() override;
    
protected:
    cocostudio::timeline::ActionTimeline* timeline;

};
//
#endif /* defined(__SushiNeko__Character__) */
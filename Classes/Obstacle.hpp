#ifndef __Obstacle__
#define __Obstacle__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

class Obstacle : public cocos2d::Node
{
public:
    CREATE_FUNC(Obstacle);
    bool init() override;
    void moveLeft(float distance);
    std::vector<cocos2d::Rect> getRects();
    void setIsPlaying(bool flag);
    void getIsPlaying();
    
protected:
    cocostudio::timeline::ActionTimeline* timeline;
    
    float velocity;
    float accel;
    bool isPlaying;
};
//
#endif /* defined(__Obstacle__) */
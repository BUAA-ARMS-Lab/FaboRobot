
#ifndef NAVIGATING_H
#define NAVIGATING_H

#include "FaboRobot.h"
#include "MapManager.h"

class FaboRobot;
class MapManager;

class Navigating
{
public:
    Navigating(){};
    ~Navigating(){};

    // 导航到目标点
    void NavigateTarget(){};
private:
    FaboRobot* mpRobot;
    MapManager* mpMapManager;
};

#endif  // NAVIGATING_H
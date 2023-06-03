
#ifndef NAVIGATING_H
#define NAVIGATING_H

#include "MapManager.h"
#include "Robot.h"

class Robot;
class MapManager;

class Navigating {
  public:
    Navigating(){};
    ~Navigating(){};

    // 导航到目标点
    void NavigateTarget(){};

  private:
    Robot *mpRobot;
    MapManager *mpMapManager;
};

#endif // NAVIGATING_H
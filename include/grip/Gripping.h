
#ifndef GRIPPING_H
#define GRIPPING_H

#include "MapManager.h"
#include "Robot.h"

class Robot;
class MapManager;

class Gripping {
  public:
    Gripping(){};
    ~Gripping(){};

    void GenerateGripPose(){};
    void GenerateArmPath(){};
    void LaunchGripping(){};
    void LaunchArmMoving(){};

  private:
    Robot *mpRobot;
    MapManager *mpMapManager;
};

#endif // GRIPPING_H
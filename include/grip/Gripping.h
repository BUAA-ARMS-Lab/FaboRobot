
#ifndef GRIPPING_H
#define GRIPPING_H

#include "FaboRobot.h"
#include "MapManager.h"

class FaboRobot;
class MapManager;

class Gripping
{
public:
    Gripping(){};
    ~Gripping(){};

    void GenerateGripPose(){};
    void GenerateArmPath(){};
    void LaunchGripping(){};
    void LaunchArmMoving(){};
private:
    FaboRobot* mpRobot;
    MapManager* mpMapManager;

};

#endif // GRIPPING_H
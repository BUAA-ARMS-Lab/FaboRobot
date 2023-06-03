
#ifndef SLAMMING_H
#define SLAMMING_H

#include "FaboRobot.h"
#include "MapManager.h"

class FaboRobot;
class MapManager;

class Slamming
{
public:
    Slamming(){};
    ~Slamming(){};

    void LaunchObjectSlamming(){};
    void LaunchGridSlamming(){};
    void OptimizeObjectParams(){};

private:
    FaboRobot* mpRobot;
    MapManager* mpMapManager;

};

#endif // SLAMMING_H
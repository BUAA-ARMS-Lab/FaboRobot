
#ifndef SLAMMING_H
#define SLAMMING_H

#include "MapManager.h"
#include "Robot.h"

class Robot;
class MapManager;

class Slamming {
  public:
    Slamming(){};
    ~Slamming(){};

    void LaunchObjectSlamming(){};
    void LaunchGridSlamming(){};
    void OptimizeObjectParams(){};

  private:
    Robot *mpRobot;
    MapManager *mpMapManager;
};

#endif // SLAMMING_H
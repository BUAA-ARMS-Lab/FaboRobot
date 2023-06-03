#include "Robot.h"


MissionState path_planning(int robot_index, const Pointd<3>& target) {
    // visit data for motion
    auto motion_states = RobotsAndMap::instance().robots_[i].motion_states_;
    auto position      = motion_states.position_;
    auto orientation   = motion_states.orientation_;
    const auto & map   = RobotsAndMap::instance().map_;
    // if position out of map or in obstacle, return EXCEPTION
    if(map.isOccupied(position)) return EXCEPTION;
    if(map.isOccupied(target))   return EXCEPTION;

    // planning paths using MAPF (Multiple Agent Path Finding)

    // if planning failed, return EXCEPTION

    // update path
    auto & path        = motion_states.path_;

    return MissionState::SUCCESS;// or EXCEPTION if failed
}
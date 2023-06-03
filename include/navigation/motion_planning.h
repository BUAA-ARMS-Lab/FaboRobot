#include "Robot.h"

// update cmd vel for the specific robot
// assume there may by more than one robot
MissionState motion_planning(int robot_index) {
    // visit data for motion 
    auto motion_states = RobotsAndMap::instance().robots_[i].motion_states_;
    auto position      = motion_states.position_;
    auto orientation   = motion_states.orientation_;
    auto velocity      = motion_states.velocity_;
    const auto & map   = RobotsAndMap::instance().map_;
    // update velocity command
    // implement DWA/TEB motion planner

    // update mission state
    auto & cmd_vel     = motion_states.cmd_vels_;
    return MissionState::SUCCESS;// RUNNING / EXCEPTION
}

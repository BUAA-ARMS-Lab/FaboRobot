
#include "Robot.h"

namespace Fabo
{

Robot *Robot::mpRobot = new (std::nothrow) Robot();

Robot *Robot::GetInstance() {
    return mpRobot;
}

void Robot::DeleteInstance() {
    if (mpRobot) {
        delete mpRobot;
        mpRobot = nullptr;
    }
}

Robot::Robot() {
    std::cout << "构造函数" << std::endl;
}

Robot::~Robot() {
    std::cout << "析构函数" << std::endl;
}

}  // namespace
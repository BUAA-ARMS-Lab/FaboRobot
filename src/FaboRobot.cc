
#include "FaboRobot.h"

FaboRobot* FaboRobot::mpFaboRobot = new (std::nothrow) FaboRobot();

FaboRobot* FaboRobot::GetInstance()
{
    return mpFaboRobot;
}

void FaboRobot::DeleteInstance()
{
    if (mpFaboRobot)
    {
        delete mpFaboRobot;
        mpFaboRobot = nullptr;
    }
}

FaboRobot::FabaRobot()
{
    std::cout << "构造函数" << std::endl;
}

FaboRobot::~FabaRobot()
{
    std::cout << "析构函数" << std::endl;
}
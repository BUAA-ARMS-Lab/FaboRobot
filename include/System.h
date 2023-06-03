
#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>

namespace Fabo
{

class Robot;
class MapManager;
class Navigating;
class Slamming;
class Gripping;
class ActiveExploring;

class System
{
public:
    System *GetInstance();
    void DeleteInstance();

private:
    static System* mpSystem;
    System(){};
    ~System(){};

    // void Init();
    // void Run();

protected:
    Robot *mpRobot;              // 机器人本体: 碰撞信息、传感器、执行器、统一控制接口
    MapManager *mpMapManager;    // 地图管理器: 管理各类地图信息
    Navigating *mpNavigator;     // 导航模块: 负责执行导航相关算法
    Slamming *mpSlammer;         // 同步定位与建图模块: 负责执行同步定位与建图相关算法
    Gripping *mpGripper;         // 抓取模块：负责执行物体操作相关算法
    ActiveExploring *mpExplorer; // 主动探索模块: 负责执行主动探索相关算法
};

}  // namespace Fabo

#endif // SYSTEM_H
#ifndef FABOROBOT_H
#define FABOROBOT_H

#include "basic_elements/point.h"
#include <iostream>
#include <vector>
// #include "basic_elements/make_singleton.h"
// #include "auto_ptr.h"

class CollisionBox;
class Head;
class Mover;
class Manipulator;
class Speaker;
class Lidar;
class HeadCamera;
class Microphone;

class Controller;

class GridMap_2D;
class OctoMap_3D;
class PointMap;
class RoomTopologyMap;
class ObjectMap;

template <typename MapType>
class Atlas {
  public:
    Atlas() {}

    MapType *mpCurrentMap;
    vector<MapType> mpMaps;
}

// 小胖机器人类，存储
class FaboRobot {
  public:
    // 获取单实例
    static FaboRobot *GetInstance();

    // 释放单实例
    static void DeleteInstance();

  private:
    // 将构造和析构函数定义为私有，禁止外部构造和析构
    FabaRobot();
    ~FaboRobot();

  private:
    // 唯一单实例对象指针
    static FaboRobot *mpFaboRobot;

  public:
    CollisionBox* mpCbox;       // 机器人本体碰撞盒
    Head* mpHead;               // 机器人头部，控制转头角度、速度，反馈执行情况和异常信息
    Mover* mpMover;             // 机器人的运动性能属性（速度/角速度限制），运动参数（位置/速度/角速度），运动状态（是否异常/异常类型）
    Manipulator* mpManipulator; // 机器人的机械臂属性（外参/关节长度/关节角度限制），机械臂参数（关节角度），机械臂状态（是否异常/异常类型）
    Speaker* mpSpeaker;         // 机器人的扬声器，用于播放音频
    Lidar* mpLidar;             // 机器人的激光雷达
    HeadCamera* mpHeadCam;      // 机器人头部的realsense相机，用于获取RGB图像/Depth图像以及IMU信息
    Microphone* mpMicrophone;   // 机器人的麦克风，接受

    // 机器人的控制指令下发（控制机器人头部、底盘与机械臂的运动）和传感信息获取（雷达、相机、IMU、麦克风）的管理器
    // 唯一占用蓝牙通道, 所有与硬件的通信都只通过该类的唯一实例进行
    Controller* mpController;

    // Atlas为多地图管理器，针对每种地图，都可能出现跟踪丢失的情况
    // 由Atlas管理该类地图的活跃地图和非活跃地图，并在重定位/检测回环时进行地图合并
    Atlas<GridMap_2D>* mpaGridMap_2D;           // 二维地图，占据概率格式，同样包括局部和全局地图，可以用于满足 基本导航 需求
    Atlas<OctoMap_3D>* mpaOctoMap_3D;           // 3D占据地图, 可以用于满足 高阶导航 和 物体交互 任务
    Atlas<PointMap>* mpaSparsePointMap;         // 稀疏点云地图
    Atlas<PointMap>* mpaDensePointMap;          // 稠密点云地图
    Atlas<RoomTopologyMap>* mpaRoomTopologyMap; // 房间拓扑地图
    Atlas<ObjectMap>* mpaObjectMap;             // 物体地图
};

class NBV; // 最佳观测点

// common basic definition of robot
struct Robot {
    // basic information of motion
    struct BaseMotion {
        Pointd<3> position_;
        Pointd<3> orientation_;
        Pointd<3> velocity_;
        Pointd<3> cmd_vel_; // v_x, v_y, v_theta
    };

    // polygon for collision check
    Pointds<2> footprint;

    BaseMotion motion_states_;

    Path path_;
};

// inherit Robot to create specific robot
typedef std::vector<Pointd<3>> Path;
typedef std::shared_ptr<Robot> RobotPtr;

// implement robot with specific requirement, for example
// struct Robot1 : public Robot {
//    //
//};
//
// struct Robot2 : public Robot {
//    //
//};
//
// struct Robot3 : public Robot {
//    //
//};

struct RobotsAndMap {

    std::vector<Robot> robots_;

    Map map_;

    MAKE_SINALETON(RobotsAndMap)
};

// running state of mission, such as navigation
enum MissionState {
    RUNNING = 0,
    SUCCESS,
    EXCEPTION
};

#endif // FABOROBOT_H
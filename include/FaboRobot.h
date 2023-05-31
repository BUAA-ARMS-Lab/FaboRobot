#include <iostream>
#include "basic_elements/point.h"
#include "basic_elements/make_singleton.h"
#include "auto_ptr.h"

class FaboRobot {
    class CollisionBox; // 机器人本体碰撞盒

    class Head;        // 转头角度，异常类型
    class Mover;       // 机器人的运动性能属性（速度/角速度限制），运动参数（位置/速度/角速度），运动状态（是否异常/异常类型）
    class Manipulator; // 机器人的机械臂属性（外参/关节长度/关节角度限制），机械臂参数（关节角度），机械臂状态（是否异常/异常类型）
    class Speaker;     // 机器人的扬声器，用于播放音频
    class Lidar;
    class Camera; // 机器人的相机，用于获取RGB图像/Depth图像，以及可能包含IMU信息
    class Microphone;

    /**
     * 所有与硬件的通信都只通过这一个类的唯一实例进行
     */
    class Controller; // 机器人的控制指令下发（控制机器人头部、底盘与机械臂的运动）和传感信息获取（雷达、相机、IMU、麦克风）的管理器

    class Atlas; // 多地图管理器

    /**
     * 地图管理
     * 1. 首先梳理各种任务所需的地图类型
     * （1）高阶导航：使用3D占据地图和机器人本体信息进行导航，包括全局地图和局部地图。
     * （2）基本导航：二维地图，占据概率格式，同样包括局部和全局地图。
     * （3）物体的主动建模：语义点云地图、房间拓扑地图、物体特征地图。
     * （4）物体抓取：
     */

  public:


};

class Atlas {
    class GridMap_2D {
      public:
        bool init = false;
    };
    class OctoMap_3D;
    class DensePointMap;
    class SparsePointMap;
    class RoomTopologyMap;
    class ObjectMap;

};

class Map {
    //

    bool isOccupied(const Pointd<3>& point); // is occupied state check
};

// common basic definition of robot
struct Robot {
    // basic information of motion
    struct BaseMotion {
        Pointd<3> position_;
        Pointd<3> velocity_;
        Pointd<3> orientation_;
        Pointd<3> cmd_vel_; // v_x, v_y, v_theta
    };

    Pointds<2> footprint;  // polygon for collision check
    BaseMotion motion_states_;
    Path  path_;
};

// inherit Robot to create specific robot

typedef std::vector<Pointd<3> > Path;
typedef std::shared_ptr<Robot> RobotPtr;

// implement robot with specific requirement, for example
//struct Robot1 : public Robot {
//    //
//};
//
//struct Robot2 : public Robot {
//    //
//};
//
//struct Robot3 : public Robot {
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














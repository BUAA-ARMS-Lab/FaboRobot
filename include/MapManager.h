
#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <iostream>

namespace Fabo
{

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
};

class MapManager
{
  public:
    // Atlas为多地图管理器，针对每种地图，都可能出现跟踪丢失的情况
    // 由Atlas管理该类地图的活跃地图和非活跃地图，并在重定位/检测回环时进行地图合并
    Atlas<GridMap_2D>* mpaGridMap_2D;           // 二维地图，占据概率格式，同样包括局部和全局地图，可以用于满足 基本导航 需求
    Atlas<OctoMap_3D>* mpaOctoMap_3D;           // 3D占据地图, 可以用于满足 高阶导航 和 物体交互 任务
    Atlas<PointMap>* mpaSparsePointMap;         // 稀疏点云地图
    Atlas<PointMap>* mpaDensePointMap;          // 稠密点云地图
    Atlas<RoomTopologyMap>* mpaRoomTopologyMap; // 房间拓扑地图
    Atlas<ObjectMap>* mpaObjectMap;             // 物体地图
};

}  // namespace Fabo

#endif // MAPMANAGER_H
#include <FaboRobot.h>


// NBV
class GlobalNBV{
    cv::Mat pose;       //NBV位姿
    double reward;      //评价值
    BackgroudObject* bo; //所属的背景物体
};

class LocalNBV{
    double angle;   //脖子的角度
    double reward;  //评价值
    int num;
};

class NBV{
    int type;       //存储的时候gn还是ln
    GlobalNBV gn;
    LocalNBV ln;
};



//拓扑地图 
class TopologyNode{
    int id;                      // 节点的唯一标识符
    std::string name;            // 房间的名称
    std::vector<int> neighbors;  // 与该节点相连的邻居节点的标识符
}



// NBVGenerator
class NBVGenerator{  //用于生成NBV

    NBV GenerateNBV(ObjectMap* obs, SparsePointMap* points, RoomTopologyMap* rooms);

};  

class ActiveExplore{

    
    
};

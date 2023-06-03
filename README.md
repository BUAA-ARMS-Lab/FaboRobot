# FaboRobot

机器人的运行所涉及到的内容包括：
- 系统 System（统筹全部其他内容）
- 机器人本体 FaboRobot（碰撞信息、传感器、执行器、统一控制接口）
- 地图管理器 MapManager（管理各类地图信息）
- 导航模块 Navigating (负责执行导航相关算法)
- 同步定位与建图模块 Slamming (负责执行同步定位与建图相关算法)
- 抓取模块 Gripping(负责执行物体操作相关算法)
- 主动探索模块 ActiveExploring (负责执行主动探索相关算法)
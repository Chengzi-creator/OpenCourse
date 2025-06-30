flowchart LR
  %% 一级模块
  subgraph 游戏架构
    direction TB
    A1(战斗系统)
    A2(UI 系统)
    A3(关卡系统)
    A4(音效/特效)
  end

  %% 战斗子模块
  subgraph 战斗系统
    direction TB
    B1(地图)
    B2(敌人)
    B3(塔)
    B4(战斗控制中心)
    A1 --> B1
    A1 --> B2
    A1 --> B3
    A1 --> B4

    %% 敌人细分
    subgraph 敌人
      direction LR
      B2_1(行为树/状态机)
      B2_2(类型：普通/精英)
      B2_3(敌人生成器)
      B2 --> B2_1
      B2 --> B2_2
      B2 --> B2_3
    end

    %% 塔细分
    subgraph 塔
      direction LR
      B3_1(塔攻击 + 特效)
      B3_2(塔技能：AOE/控制)
      B3 --> B3_1
      B3 --> B3_2
    end

    %% 战斗控制中心细分
    subgraph 战斗控制中心
      direction TB
      B4_1(管理流程/波次/胜负条件)
      B4_2(调度：地图/敌人生成器/塔)
      B4 --> B4_1
      B4 --> B4_2
    end
  end

  %% UI 子模块
  subgraph UI 系统
    direction TB
    C1(关卡选择界面)
    C2(战斗界面)
    A2 --> C1
    A2 --> C2
  end

  %% 关卡子模块
  subgraph 关卡系统
    direction TB
    D1(地图类型：分支地图)
    D2(关卡配置表：敌人波次)
    A3 --> D1
    A3 --> D2
    %% 关卡配置驱动敌人生成
    D2 --> B2_3
  end

  %% 音效/特效子模块
  subgraph 音效/特效
    direction LR
    E1(音效管理)
    E2(特效管理)
    A4 --> E1
    A4 --> E2
    E1 --> A1
    E2 --> B3_1
  end

  %% 跨系统关联
  C2 --> A1
  D1 --> B1

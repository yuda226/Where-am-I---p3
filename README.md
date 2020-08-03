# Where-am-I---p3
udacity where am I Project3

## Installation
```
git clone https://github.com/yuda226/Where-am-I---p3.git 
catkin_make
```
## Run the Project
```
source devel/setup.bash
roslaunch my_robot world.launch

roslaunch my_robot amcl.launch
```
![Whereami](/docs/amcl_localized01.png)  

```
roslaunch my_robot mapping.launch
```
![Whereami](/docs/mapping_rtabmap.png)  

```
roslaunch my_robot localization.launch
```
![Whereami](/docs/localization_rtabmap.png)  

```
rosrun teleop_twist_keyboard teleop_twist_keyboard.py 
```
## Directory Structure

```
.
├── CMakeLists.txt
├── docs
│   ├── amcl_localization_video01.mkv
│   ├── amcl_localized01.png
│   ├── amcl_localized_initialization.png
│   ├── localization_rtabmap.png
│   └── mapping_rtabmap.png
├── my_robot
│   ├── CMakeLists.txt
│   ├── config
│   │   ├── base_local_planner_params.yaml
│   │   ├── costmap_common_params.yaml
│   │   ├── global_costmap_params.yaml
│   │   ├── local_costmap_params.yaml
│   │   └── __MACOSX
│   ├── launch
│   │   ├── amcl.launch
│   │   ├── localization.launch
│   │   ├── mapping.launch
│   │   ├── robot_description.launch
│   │   ├── udacity_bot_description.launch
│   │   ├── udacity_bot_world.launch
│   │   └── world.launch
│   ├── maps
│   │   ├── myhouse.pgm
│   │   ├── myhouse.yaml
│   │   ├── myoffice.pgm
│   │   └── myoffice.yaml
│   ├── meshes
│   │   └── hokuyo.dae
│   ├── package.xml
│   ├── rviz
│   │   └── myrobot.rviz
│   ├── urdf
│   │   ├── materials.xacro
│   │   ├── project2robot.gazebo
│   │   ├── project2robot.xacro
│   │   ├── udacity_bot.gazebo
│   │   └── udacity_bot.xacro
│   └── worlds
│       ├── empty.world
│       ├── myhouse.world
│       ├── myoffice.world
│       ├── robothouseworld
│       └── robothouse.world
├── README.md
└── teleop_twist_keyboard
    ├── CHANGELOG.rst
    ├── CMakeLists.txt
    ├── package.xml
    ├── README.md
    └── teleop_twist_keyboard.py
```
### Debug 
```
with the myhouse.world, initial pose lost thus tf transmission failed.
added myoffice.world, both 2wheel & 4wheel robots runs smoothly.
```


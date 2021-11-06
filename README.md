# Square equation solver (ROS NODE)
***

Install
=====================
1. cd <your_ros_workspace>/src
2. git clone https://github.com/Ilya-Belyanov/Ros_Nodes.git

Build
=====================
1. cd <your_ros_workspace>
2. catkin_make

Run
=====================
0. roscore
1. Open other terminal
2. cd <your_ros_workspace>
3. source devel/setup.bash
4. rosrun square_equation_solver square_equation_solver_node

Examples Using Service
=====================
1. Initial
   1. cd <your_ros_workspace>
   2. source devel/setup.bash
2. rosservice call /square_equation *"a: 1.0 b: 8.0 c: 3.0"*
    1. output from node console = *x1 = -0.394449, x2 = -7.605551*
    2. out from service console = *roots: [-0.39444875717163086, -7.605551242828369]*
3. rosservice call /square_equation *"a: 1.0 b: 6.0 c: 9.0"*
   1. output from node console = *x = -3.000000*
   2. out from service console = *roots: [-3.0]*
4. rosservice call /square_equation *"a: 1.0 b: 2.0 c: 17.0"*
   1. output from node console = *No roots!*
   2. out from service console = *roots: [ ]*


Build and Run Using CLion
=====================
https://www.jetbrains.com/help/clion/ros-setup-tutorial.html
    


		
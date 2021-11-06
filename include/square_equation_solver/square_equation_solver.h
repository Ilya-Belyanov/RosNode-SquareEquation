#ifndef SQUARE_EQUATION_SOLVER_HPP
#define SQUARE_EQUATION_SOLVER_HPP

#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"
#include "square_equation_solver/square_equation_srv.h"

class SquareEquationSolver
{

    ros::NodeHandle *node_;
    ros::Publisher solve_publisher_;
    ros::ServiceServer service_server_;

public:
    SquareEquationSolver(ros::NodeHandle *node);

private:
    bool solve(square_equation_solver::square_equation_srv::Request &req,
               square_equation_solver::square_equation_srv::Response &res);

    std_msgs::Float32MultiArray getRoots(square_equation_solver::square_equation_srv::Request &req);
    float discriminant(float a, float b, float c);
};
#endif // SQUARE_EQUATION_SOLVER_HPP

#include "square_equation_solver/square_equation_solver.h"

SquareEquationSolver::SquareEquationSolver(ros::NodeHandle *node)
{
    node_ = node;
    std::string topic;
    if(node_->getParam("square_equation_topic", topic))
        solve_publisher_ = node_->advertise<std_msgs::Float32MultiArray>(topic, 1000);
    service_server_ = node_->advertiseService("square_equation", &SquareEquationSolver::solve, this);
}

bool SquareEquationSolver::solve(square_equation_solver::square_equation_srv::Request &req,
                                 square_equation_solver::square_equation_srv::Response &res)
{
    std_msgs::Float32MultiArray msg = getRoots(req);
    res.roots = msg.data;
    solve_publisher_.publish(msg);
    return true;
}

std_msgs::Float32MultiArray SquareEquationSolver::getRoots(square_equation_solver::square_equation_srv::Request &req)
{
    std_msgs::Float32MultiArray roots;
    float disc = discriminant(req.a, req.b, req.c);
    if(disc > 0)
    {
        float x1 = (-req.b + std::sqrt(disc)) / (2 * req.a);
        float x2 = (-req.b - std::sqrt(disc)) / (2 * req.a);
        roots.data.push_back(x1);
        roots.data.push_back(x2);
    }
    else if(int(disc) == 0)
    {
        float x = -req.b / (2 * req.a);
        roots.data.push_back(x);
    }
    return roots;
}

float SquareEquationSolver::discriminant(float a, float b, float c)
{
    return std::pow(b, 2.0) - 4 * a * c;
}
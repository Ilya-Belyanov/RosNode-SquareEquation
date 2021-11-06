#include "square_equation_solver/square_equation_result_subscriber.h"


SquareEquationResultSubscriber::SquareEquationResultSubscriber(ros::NodeHandle *node)
{
    node_ = node;
    std::string topic;
    if(node_->getParam("square_equation_topic", topic))
        result_subscriber_ = node_->subscribe(topic, 1000, &SquareEquationResultSubscriber::receive, this);
}

void SquareEquationResultSubscriber::receive(const std_msgs::Float32MultiArray &result)
{
    if(result.data.size() == 2)
        ROS_INFO("x1 = %f, x2 = %f", result.data.at(0), result.data.at(1));
    else if(result.data.size() == 1)
        ROS_INFO("x = %f", result.data.at(0));
    else if(result.data.empty())
        ROS_INFO("No roots!");
    else
        ROS_INFO("Invalid response!");
}

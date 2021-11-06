#ifndef SQUARE_EQUATION_RESULT_SUBSCRIBER_HPP
#define SQUARE_EQUATION_RESULT_SUBSCRIBER_HPP

#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"

class SquareEquationResultSubscriber
{
    ros::NodeHandle *node_;
    ros::Subscriber result_subscriber_;

public:
    SquareEquationResultSubscriber(ros::NodeHandle *node);

private:
    void receive(const std_msgs::Float32MultiArray &result);
};
#endif // SQUARE_EQUATION_RESULT_SUBSCRIBER_HPP

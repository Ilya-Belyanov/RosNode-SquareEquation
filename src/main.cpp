#include "square_equation_solver/square_equation_solver.h"
#include "square_equation_solver/square_equation_result_subscriber.h"


int main(int argc, char **argv)
{
    ros::init(argc, argv, "square_equation_solver");
    ros::NodeHandle node;
    node.setParam("square_equation_topic", "/square_equation_solver/result");

    SquareEquationSolver squareEquationSolver(&node);
    SquareEquationResultSubscriber resultSubscriber(&node);

    ros::spin();
    return 0;
}

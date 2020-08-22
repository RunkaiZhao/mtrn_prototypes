#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "geometry_msgs/Twist.h"
#include <sstream>

class vel_2_pow {
public:
    vel_2_power();

private:
    void converterCallback(const geometry_msgs::Twist:ConstPtr& msg);

    //Ceate a handle to process the node
    ros::NodeHandler node;

    ros::Publisher leftFront_pow_pub;
    ros::Publisher rightFront_pow_pub;
    ros::Publisher leftBack_pow_pub;
    ros::Publisher rightBack_pow_pub;
    ros::Subscriber vel_pow_sub;

}
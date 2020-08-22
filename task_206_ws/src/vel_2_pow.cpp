#inlcude "vel_2_pow.hpp"

vel_2_pow::vel_2_power() {
    
    vel_pow_pub[0] = this->nh.advertise<std_msgs::Float64>("/Move_LF", 1)
    vel_pow_pub[1] = this->nh.advertise<std_msgs::Float64>("/Move_RF", 1);
    vel_pow_pub[2] = this->nh.advertise<std_msgs::Float64>("/Move_LB", 1);
    vel_pow_pub[3] = this->nh.advertise<std_msgs::Float64>("/Move_RB", 1);
    vel_pow_sub = this->nh.subscribe("/JoystickInput", 1, &vel_2_pow::converterCallback, this);

}

void vel_2_pow::converterCallback(const geometry_msgs::Twist:ConstPtr& msg) {

    std_msgs::Float64 xValue = msg->Linear.x; //Move forward or backward
    std_msgs::Float64 yValue = msg->Linear.y; //Turning
    std_msgs::Float64 powPercent = 0.0;
    std_msgs::Float64 angle = 0.0;

    if (yValue == 0) { // Without turning
        powPercent = xValue / this->maxSpeed;
        for (int i = 0; i < 4; i++) {
            vel_pow_pub[i].publish(powPercent);   
        }
    }
    else if (xValue > 0 || xValue == 0) { // moving forward, the power percentage should be positive
        angle = atan(xValue / yValue);
        powPercent = abs(angle) / 90.0;

        for (int i = 0; i < 4; i++) {
            vel_pow_pub[i].publish(powPercent);   
        }
    }
    else if (xValue < 0) { // moving backward, the power percentage should be positive
        angle = atan(xValue / yValue);
        powPercent = -(abs(angle) / 90.0);

        for (int i = 0; i < 4; i++) {
            vel_pow_pub[i].publish(powPercent);   
        }
    }

}

int main(int argc, char** argv)
{
    //Initialize ROS
    ros::init(argc, argv, "vel_2_pow");

    vel_2_pow vel2pow_node;

    ros::spin();
}
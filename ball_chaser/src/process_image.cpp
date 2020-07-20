#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // TODO: Request a service and pass the velocities to it to drive the robot
    ball_chaser::DriveToTarget drive_cmd;
    drive_cmd.request.linear_x = lin_x;
    drive_cmd.request.angular_z = ang_z;

    if (!client.call(drive_cmd)){
        ROS_ERROR("Failed to execute drive command");
    }
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    float x, z;
    bool col_flag=false;
    int col_value=0;

    // TODO: Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    // Request a stop when there's no white ball seen by the camera

    for(int i=0; i<img.height*img.step;i=i+3)
    {
         if (img.data[i] == white_pixel && img.data[i+1]==white_pixel && img.data[i+2]==white_pixel)
         {
            col_flag=true;
            col_value=i%img.step;
            break;
        }
    }
    if (col_flag) { // no pixels found turn until you find some.

        int LeftBound=(img.step)/3;
        int RightBound=(img.step)/3*2;
        if (col_value>(LeftBound)&&col_value<(RightBound)){
            ROS_INFO("The ball at the center! Chase!");
            x = 0.5;
            z = 0;
        }
        if (col_value<(LeftBound)) {
            ROS_INFO("The ball at the left!");
            x = 0.0;
            z = 0.5;
        }
        if (col_value>(RightBound)) {
            ROS_INFO("The ball at the right!");
            x = 0.0;
            z = -0.5;
        }
    }
    else {
        
        ROS_INFO("Where is the ball?");
            x = 0.0;
            z = 2.0;
    }
    drive_robot(x,z);
}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}

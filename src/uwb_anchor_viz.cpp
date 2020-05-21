#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "uwb_anchor_plant");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker1_pub = n.advertise<visualization_msgs::Marker>("uwb_anchor_1_marker", 1);
  ros::Publisher marker2_pub = n.advertise<visualization_msgs::Marker>("uwb_anchor_2_marker", 1);
  ros::Publisher marker3_pub = n.advertise<visualization_msgs::Marker>("uwb_anchor_3_marker", 1);
  ros::Publisher marker4_pub = n.advertise<visualization_msgs::Marker>("uwb_anchor_4_marker", 1);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CYLINDER;

  while (ros::ok())
  {
    visualization_msgs::Marker marker_anchor_1;
    visualization_msgs::Marker marker_anchor_2;
    visualization_msgs::Marker marker_anchor_3;
    visualization_msgs::Marker marker_anchor_4;
    
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker_anchor_1.header.frame_id = "/my_frame";
    marker_anchor_2.header.frame_id = "/my_frame";
    marker_anchor_3.header.frame_id = "/my_frame";
    marker_anchor_4.header.frame_id = "/my_frame";
    marker_anchor_1.header.stamp = ros::Time::now();
    marker_anchor_2.header.stamp = ros::Time::now();
    marker_anchor_3.header.stamp = ros::Time::now();
    marker_anchor_4.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker_anchor_1.ns = "uwb_anchor_plant";
    marker_anchor_2.ns = "uwb_anchor_plant";
    marker_anchor_3.ns = "uwb_anchor_plant";
    marker_anchor_4.ns = "uwb_anchor_plant";
    marker_anchor_1.id = 0;
    marker_anchor_2.id = 0;
    marker_anchor_3.id = 0;
    marker_anchor_4.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker_anchor_1.type = shape;
    marker_anchor_2.type = shape;
    marker_anchor_3.type = shape;
    marker_anchor_4.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker_anchor_1.action = visualization_msgs::Marker::ADD;
    marker_anchor_2.action = visualization_msgs::Marker::ADD;
    marker_anchor_3.action = visualization_msgs::Marker::ADD;
    marker_anchor_4.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker_anchor_1.pose.position.x = 0;
    marker_anchor_1.pose.position.y = 0;
    marker_anchor_1.pose.position.z = 0;
    marker_anchor_1.pose.orientation.x = 0.0;
    marker_anchor_1.pose.orientation.y = 0.0;
    marker_anchor_1.pose.orientation.z = 0.0;
    marker_anchor_1.pose.orientation.w = 1.0;
    
    marker_anchor_2.pose.position.x = 2.83;
    marker_anchor_2.pose.position.y = 0;
    marker_anchor_2.pose.position.z = 0;
    marker_anchor_2.pose.orientation.x = 0.0;
    marker_anchor_2.pose.orientation.y = 0.0;
    marker_anchor_2.pose.orientation.z = 0.0;
    marker_anchor_2.pose.orientation.w = 1.0;
    
    marker_anchor_3.pose.position.x = 2.83;
    marker_anchor_3.pose.position.y = 2.15;
    marker_anchor_3.pose.position.z = 0;
    marker_anchor_3.pose.orientation.x = 0.0;
    marker_anchor_3.pose.orientation.y = 0.0;
    marker_anchor_3.pose.orientation.z = 0.0;
    marker_anchor_3.pose.orientation.w = 1.0;
    
    marker_anchor_4.pose.position.x = 0;
    marker_anchor_4.pose.position.y = 2.15;
    marker_anchor_4.pose.position.z = 0;
    marker_anchor_4.pose.orientation.x = 0.0;
    marker_anchor_4.pose.orientation.y = 0.0;
    marker_anchor_4.pose.orientation.z = 0.0;
    marker_anchor_4.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker_anchor_1.scale.x = 0.1;
    marker_anchor_1.scale.y = 0.1;
    marker_anchor_1.scale.z = 2.0;
    
    marker_anchor_2.scale.x = 0.1;
    marker_anchor_2.scale.y = 0.1;
    marker_anchor_2.scale.z = 2.0;
    
    marker_anchor_3.scale.x = 0.1;
    marker_anchor_3.scale.y = 0.1;
    marker_anchor_3.scale.z = 2.0;
    
    marker_anchor_4.scale.x = 0.1;
    marker_anchor_4.scale.y = 0.1;
    marker_anchor_4.scale.z = 2.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker_anchor_1.color.r = 0.0f;
    marker_anchor_1.color.g = 1.0f;
    marker_anchor_1.color.b = 0.0f;
    marker_anchor_1.color.a = 1.0;
    
    marker_anchor_2.color.r = 0.0f;
    marker_anchor_2.color.g = 1.0f;
    marker_anchor_2.color.b = 0.0f;
    marker_anchor_2.color.a = 1.0;
    
    marker_anchor_3.color.r = 0.0f;
    marker_anchor_3.color.g = 1.0f;
    marker_anchor_3.color.b = 0.0f;
    marker_anchor_3.color.a = 1.0;
    
    marker_anchor_4.color.r = 0.0f;
    marker_anchor_4.color.g = 1.0f;
    marker_anchor_4.color.b = 0.0f;
    marker_anchor_4.color.a = 1.0;

    marker_anchor_1.lifetime = ros::Duration();
    marker_anchor_2.lifetime = ros::Duration();
    marker_anchor_3.lifetime = ros::Duration();
    marker_anchor_4.lifetime = ros::Duration();
    

    // Publish the marker
    while (marker1_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
//       ROS_INFO_ONCE("Please create a subscriber to the marker");
      ROS_WARN_ONCE("Please display the uwb marker in Rviz");
      sleep(1);
    }
    marker1_pub.publish(marker_anchor_1);
    marker2_pub.publish(marker_anchor_2);
    marker3_pub.publish(marker_anchor_3);
    marker4_pub.publish(marker_anchor_4);
    // Cycle between different shapes
//     switch (shape)
//     {
//     case visualization_msgs::Marker::CUBE:
//       shape = visualization_msgs::Marker::SPHERE;
//       break;
//     case visualization_msgs::Marker::SPHERE:
//       shape = visualization_msgs::Marker::ARROW;
//       break;
//     case visualization_msgs::Marker::ARROW:
//       shape = visualization_msgs::Marker::CYLINDER;
//       break;
//     case visualization_msgs::Marker::CYLINDER:
//       shape = visualization_msgs::Marker::CUBE;
//       break;
//     }

    r.sleep();
  }
}

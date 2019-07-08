#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>

int user_data;



int
 main (int argc, char** argv)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);

 pcl::io::loadPCDFile ("globe.pcd", *cloud_in);
 pcl::io::loadPCDFile ("globe_in_scene.pcd", *cloud_out);


  
  std::cout << "size:" << cloud_out->points.size() << std::endl;
  for (size_t i = 0; i < cloud_in->points.size (); ++i)
    cloud_out->points[i].x = cloud_in->points[i].x + 0.7f;
  std::cout << "Transformed " << cloud_in->points.size () << " data points:"
      << std::endl;
  for (size_t i = 0; i < cloud_out->points.size (); ++i)
    std::cout << "    " << cloud_out->points[i].x << " " <<
      cloud_out->points[i].y << " " << cloud_out->points[i].z << std::endl;
  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setInputSource(cloud_in);
  icp.setInputTarget(cloud_out);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align(Final);
  std::cout << "\nhas converged(status):" << icp.hasConverged() << " \nscore: " <<
  icp.getFitnessScore() << std::endl;
  std::cout<<"Transformation Matrix:"<<endl;
  std::cout << icp.getFinalTransformation() << std::endl;



pcl::io::savePCDFileASCII ("transform_pcd.pcd", Final);
  std::cerr << "Saved " << Final.points.size () << " data points to transform_pcd.pcd." << std::endl;
    
    
    pcl::PointCloud<pcl::PointXYZ>::Ptr Final1 (new pcl::PointCloud<pcl::PointXYZ>);

pcl::io::loadPCDFile ("transform_pcd.pcd", *Final1);
    pcl::visualization::CloudViewer viewer1("Transformed");
  viewer1.showCloud(Final1);  //blocks until the cloud is actually rendered

  //This will only get called once

    //This will get called once per visualization iteration
   
    while (!viewer1.wasStopped ())
    {
    //you can also do cool processing here
    //FIXME: Note that this is running in a separate thread from viewerPsycho
    //and you should guard against race conditions yourself...
    user_data++;
    }





 return (0);
}
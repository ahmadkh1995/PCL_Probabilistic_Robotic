#include <QCoreApplication>
#include <pcl/visualization/cloud_viewer.h>
#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

int user_data;

void
viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{
   
    std::cout << "i only run once" << std::endl;

}



int main ()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile ("globe.pcd", *cloud);
    pcl::visualization::CloudViewer viewer("Globe in Scene");
    viewer.showCloud(cloud);  //blocks until the cloud is actually rendered

   //pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2 (new pcl::PointCloud<pcl::PointXYZ>);
   // pcl::io::loadPCDFile ("globe.pcd", *cloud2);
   // pcl::visualization::CloudViewer viewer2("Cloud Viewer 2");
   // viewer2.showCloud(cloud2);  //blocks until the cloud is actually rendered


    //This will only get called once
    viewer.runOnVisualizationThreadOnce (viewerOneOff);

    //This will get called once per visualization iteration
   
    while (!viewer.wasStopped ())
    {
    //you can also do cool processing here
    //FIXME: Note that this is running in a separate thread from viewerPsycho
    //and you should guard against race conditions yourself...
    user_data++;
    }
    return 0;
}

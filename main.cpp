#define CL_HPP_TARGET_OPENCL_VERSION 200
#define CL_HPP_ENABLE_EXCEPTIONS
#define CL_TARGET_OPENCL_VERSION 220

#include <QCoreApplication>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <fstream>
#include <CL/opencl.h>
#include <ctime>
#include <cstdlib>
#include <sys/timeb.h>
#include <iostream>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
cl_device_id device_id = NULL;
cl_platform_id platform_id = NULL;
cl_int ret;
cl_uint ret_num_platforms;
cl_uint ret_num_devices;
    cl_int err = CL_SUCCESS;

    // Get (in numPlatforms) the number of OpenCL platforms available
    // No platform ID will be return, since platforms is NULL

    ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
    if (CL_SUCCESS != ret)
    {
        std::cout<<"Error: Platform"<<std::endl;
        return -1;
    }
    ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

    if (CL_SUCCESS != err)
    {
           std::cout<<"Error: Device"<<std::endl;
        return ret;
    }
    size_t stringLength = 0;
    ret = clGetDeviceInfo(device_id, CL_DEVICE_VERSION, 0, NULL, &stringLength);
        if (CL_SUCCESS != ret)
        {
               std::cout<<"Error: Device Info"<<std::endl;
            return ret;
        }

        // Now, that we know the device's version string length, we can allocate enough space before read it
        std::vector<char> deviceVersion(stringLength);

        // Read the device's version string
        // The read value returned in deviceVersion
        clGetDeviceInfo(device_id, CL_DEVICE_VERSION, stringLength, &deviceVersion[0], NULL);

         std::cout<<":::"<<deviceVersion.data() <<std::endl;
         return 0;
    return a.exec();
}

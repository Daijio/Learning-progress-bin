#include <iostream>
using namespace std;

//使用c库
extern "C"
{
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <sys/mman.h>
    #include <unistd.h>
}

//驱动对象：dev/fb0
int open(const char *pathname="/dev/fb0",int flags=O_RDWR)
{
    int lcdfd=open(pathname,flags);
    if(lcdfd==-1)
    {
        perror("lcd error\n");
        return -1;
    }
    return lcdfd;
}

int main() 
{
    //1.打开设备
    int fd = lcdopen();
    //映射到Ubuntu
    unsigned int *p = (unsigned int *)mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    
    //准备颜色
    unsigned int green ==0x0000ff00;
    //写入到屏幕
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<800*480;i++)
        {
            p[i]=green;
        }
        sleep(5);
    }

    //取消映射和关闭
    munmap(p,800*480*4);
    close(fd);
    return 0;
}
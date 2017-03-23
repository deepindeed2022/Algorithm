/********************************************************
 * Description: The source code for scap the mouse click event
 * Author: wenlong
 * Date: 2016-11-08
 * 
 ********************************************************/
#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
// if TEST_BY_CLOCK test a operation using CPU click time, not include idle clicks
#define TEST_BY_CLOCK 0

#define  __DEBUG__  1
double getTimeval()
{
	struct timeval stTimeval;
	gettimeofday(&stTimeval, NULL);
	return stTimeval.tv_sec + (double)stTimeval.tv_usec*1E-6;
}

// #define __KB_EVENT__ 1

#ifndef __KB_EVENT__
int main(int argc,char **argv)
{
    int fd, retval;
    char buf[6];
    fd_set readfds;
    struct timeval tv;
    #if TEST_BY_CLOCK
    	clock_t t1, t2;
    #else
	double t1, t2;
    #endif

    int flag = 0;
    if(( fd = open("/dev/input/mice", O_RDONLY))<0)
    {
        printf("Failed to open \"/dev/input/mice\".\n");
        printf("You should try root adminstrator to execute\n");
        return 1;
    }
    else
    {
        printf("open \"/dev/input/mice\" successfuly.\n");
    }
    while(1)
    {
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        FD_ZERO(&readfds);
        FD_SET(fd, &readfds);

        retval = select(fd+1, &readfds, NULL, NULL, &tv);
        if(retval == 0)
            printf("Read mouse input time out!\n");

        if(FD_ISSET(fd, &readfds))
        {
            if(read(fd, buf, 6) <= 0)//终端设备，一次只能读取一行
            {
                continue;
            }
            #if  __DEBUG__
                // printf("Button type = %d, X = %d, Y = %d, Z = %d\n", (buf[0] & 0x07), buf[1], buf[2],   buf[3]);
            #endif
            // mouse left click
            if((buf[0] & 0x07) == 1 && flag == 0)
            {
                flag = 1;
                #if __DEBUG__
                    printf("%s\n","Left click, application start...");
                #endif
				#if TEST_BY_CLOCK
					t1 = clock();
				#else 
					t1 = getTimeval();
                #endif
            }
            // mouse right click
            if((buf[0] & 0x07) == 2 && flag == 1)
            {
				
				#if TEST_BY_CLOCK
					t2 = clock() - t1;
					printf("Loading Application using:%ld clicks, %fs\n",t2, (float)(t2)/CLOCKS_PER_SEC);
				#else
					t2 = getTimeval() - t1;
					printf("Loading Application using:%lfs\n", t2);
				#endif

                flag = 0;
                
            }

        }
    }
    close(fd);
    return 0;
}

#endif


#ifdef __KB_EVENT__
int main()  
{  
        int fd_kb; 
        clock_t t1 = 0, t2 = 0;
        struct input_event event_kb;  
        if((fd_kb = open("/dev/input/event4", O_RDONLY)) <= 0)  
        {  
            printf("open device error\n");  
            return 0;  
        }

        while(1)  
        {             
                if(read(fd_kb, &event_kb, sizeof(event_kb)) == sizeof(event_kb))  
                {                                         
                    if(event_kb.code == BTN_LEFT)//左键按下，1表示按下，0表示释放。不然会检测到两次  
                    {
                        //printf("left down: %d\n", event_kb.code);
                        printf("%s\n","Start an application");
                        t1 = clock();
                    }   
                          
                    if(event_kb.code == BTN_RIGHT)
                    {
                        // printf("right down: %d\n", event_kb.code);
                        printf("%s\n", "Application Loading finished");
                        t2 = clock();
                    }

                    if(event_kb.code == KEY_ESC)
                    {
                        printf("Loading Application using:%ld clock = %lfs\n",t2 - t1, (double)(t2-t1)/CLOCKS_PER_SEC);
                        break;      
                    }
                    if(event_kb.code == KEY_Q  && event_kb.value==1)
                    {
                        printf("%s\n","click Q" );
                    }
                    printf("event type:%d\n", event_kb.type);

                }else
                {
                    printf("%s\n","Read nothing");
                }
        }
        close(fd_kb);  
        return 0;  
} 
#endif
/**
struct input_event {

    struct timeval time;  //按键时间

    __u16 type;  //事件的类型

    __u16 code;  //要模拟成什么按键

    __s32 value;  //是按下1还是释放0

};

http://blog.csdn.net/shijian408/article/details/26578007

http://blog.csdn.net/u013467442/article/details/51174852
**/

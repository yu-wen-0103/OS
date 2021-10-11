#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MEGA 1024*1024
//all be CPU bound task
//perf_bench-2.c >> perf_bench-1.c

int memoryArray[MEGA];
long loopCount=0;
int myrand;

int main(int argc, char** argv) {
    for (loopCount = 0; loopCount < 5000000000; loopCount++)
    {	
        myrand += 779;
        myrand %= 100;
        memoryArray[loopCount % MEGA] += myrand;
    }
    exit(0);
}

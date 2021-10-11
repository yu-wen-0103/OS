#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>

long timespec2nano(struct timespec ts)
{
    return ts.tv_sec * 1000000000 + ts.tv_nsec;
}

int main(int argc,char**argv) {
    int pid1, pid2;
    int res;
    int eatResult; 
    char execute[100];
    struct timespec t1, t2;
    strcpy(execute,"./");
    strcat(execute,argv[1]);
    pid1 = fork();//create thread
    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(0, &set);
    clock_gettime(CLOCK_MONOTONIC_RAW, &t1);
    if (pid1 == 0)
    { //child1
        assert(sched_setaffinity(getpid(), sizeof(set), &set) != -1);
        eatResult = system(execute);
        exit(0);
    }
    wait(&res);//end thread
    pid2 = fork();
    if (pid2 == 0)
    { //child2
        assert(sched_setaffinity(getpid(), sizeof(set), &set) != -1);
        eatResult = system(execute);
        exit(0);
    }
    wait(&res);
    clock_gettime(CLOCK_MONOTONIC_RAW, &t2);
    printf("%f sec\n", ((double)timespec2nano(t2) - timespec2nano(t1)) / 1000000000);
}

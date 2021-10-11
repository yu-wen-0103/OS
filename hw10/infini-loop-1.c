#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define MEGA 1024*1024
//once CPU once IO task
//perf_bench-1.c >> perf_bench-2.c

int memoryArray[MEGA];
long loopCount=0;
int myrand;
//int m_a[MEGA];
//int eatresult=0;

int main(int argc, char** argv) {
	FILE *fp=fopen("test.txt","w+");
	long size;
	size=ftell(fp);

    for (loopCount = 0; loopCount < 500000000; loopCount++)
    {
	if(size > 100000000)//60MB
		break;
	fwrite("OA",1,sizeof(2),fp);
	size=ftell(fp);
	//if(size % (1000000) ==0)
	//	printf("%ld MB\n",size/1000000);

        myrand += 779;
        myrand %= 100;
        memoryArray[loopCount % MEGA] += myrand;
    }
    printf("Size = %ld\n",size);
    fclose(fp);
    exit(0);
}

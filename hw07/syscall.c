#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char** argv) {
    char* hello = "hello world\n";    
    int len = strlen(hello)+1;
    long ret;
    
    __asm__ volatile ( 
        "mov $4, %%rax\n"
        "mov $2, %%rbx\n"
        "mov %1, %%rcx\n"
        "mov %2, %%rdx\n"
        "int $0x80\n"
        "mov %%rax, %0"
        :  "=m"(ret)
        : "g" (hello), "g" (len)
        : "rax", "rbx", "rcx", "rdx");
    printf("return:%ld\n",ret);
}

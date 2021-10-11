#include <stdio.h>
int main(int argc, char** argv) {
    unsigned long msr;
    asm volatile ( "rdtsc\n\t"  // Returns the time in EDX:EAX.
        "shl $32, %%rdx\n\t"    // Shift the upper bits left.
        "or %%rdx, %%rax\n"          // 'Or' in the lower bits.
        "mov %%rax, %0\n"
       	: "=m" (msr)            //msr?ƒæ”¾?¨è??¶é?
        :
        : "rdx");
    printf("msr: %lx\n", msr);
}

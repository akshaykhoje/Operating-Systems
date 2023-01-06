/*
Take any 4 of your DSA-1 programs, compile them using gcc -S and see the assembly code. Draw a diagram of how the stack is built and wound up. Try to understand how the calling convention is followed. Try to have programs which use local variables, static varibles, static globals, globals, and also a program which is split into multiple files.
*/

/*
1. Write a C program to find out the size of variables of different data types (use sizeof()
operator) and display their size as output.
*/

#include <stdio.h>

int main() {
    int a;
    printf("size of int : %d\n", (int)sizeof(a));

    float f;
    printf("size of float : %d\n", (int)sizeof(f));

    char c;
    printf("size of char : %d\n", (int)sizeof(c)); 

    double d;
    printf("size of double : %d\n", (int)sizeof(d));
    return 0;
}
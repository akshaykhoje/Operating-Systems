#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int main(void) {
    int a, b;
    printf("Enter the two numbers you want to add : ");
    scanf("%d %d", &a, &b);
    int result = add(a,b);
    printf("The addition is : %d\n", result);
    return 0;
}
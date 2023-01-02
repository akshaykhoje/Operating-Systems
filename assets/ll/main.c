#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int main(void) {
    ll node;
    init(&node);
    // printf("Successful init function!\n");
    create(&node, 43);
    create(&node, 12);
    create(&node, 89);
    create(&node, 999);
    create(&node, 90949);
    create(&node, 11);
    create(&node, -234);
    display(node);
    delNode(&node, 999);
    display(node);
    delNode(&node, 89);
    display(node);
    delNode(&node, 43);
    display(node);
    create(&node, -314);
    display(node);
    ll target = search(node, 11);
    printf("data : %d\n", target->next->data);
    return 0;
}
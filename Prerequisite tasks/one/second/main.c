#include <stdio.h>
#include <stdlib.h>
#include "dcll.h"

int main(void) {
    dcll node;
    init(&node);
    insert(&node, "./students_data.csv");
    display_clockwise(node);
    display_counter_clockwise(node);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "dcll.h"

int main(void) {
    dcll node;
    init(&node);
    insert_beginning(&node);
    display_clockwise(node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    display_clockwise(node);
    display_counter_clockwise(node);
    delete_beginning(&node);
    display_clockwise(node);
    display_counter_clockwise(node);
    delete_ending(&node);
    display_clockwise(node);
    display_counter_clockwise(node);
    return 0;
}
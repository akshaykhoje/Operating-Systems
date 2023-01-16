#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

int main(void) {
    dll node;
    init(&node);
    insert_beginning(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    display(node);
    insert_after(&node);
    display(node);
    insert_after(&node);
    display(node);
    display_back(node);
    delete_beginning(&node);
    display(node);
    display_back(node);
    delete_ending(&node);
    display(node);
    display_back(node);
    delete_char(&node);
    display(node);
    display_back(node);
    dll ptr = search(node);
    printf("data : %c\n", ptr->data);
    return 0;
}
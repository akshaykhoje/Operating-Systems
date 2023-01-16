#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main(void) {
    cll node;
    init(&node);
    insert_beginning(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    insert_ending(&node);
    display(node);
    delete_beginning(&node);
    display(node);
    insert_ending(&node);
    display(node);
    delete_ending(&node);
    display(node);

    cll ptr = search(node);
    printf("%c  ", ptr->data);
    
    return 0;
}
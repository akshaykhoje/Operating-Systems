
typedef struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef Node *dll;

void init(dll *rootptr);
void insert_beginning(dll *rootptr);
void insert_ending(dll *rootptr);
void insert_after(dll *rootptr);
void display(dll rootptr);
void display_back(dll rootptr);
void delete_beginning(dll *rootptr);
void delete_ending(dll *rootptr);
void delete_char(dll *rootptr);
dll search(dll rootptr);

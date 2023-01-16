
typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef Node *cll;

void init(cll *rootptr);
void insert_beginning(cll *rootptr);
void insert_ending(cll *rootptr);
void delete_beginning(cll *rootptr);
void delete_ending(cll *rootptr);
void display(cll rootptr);
cll search(cll rootptr);
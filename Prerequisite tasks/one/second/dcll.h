
typedef struct Node {
    char *name;
    int MIS;
    double marks;
    struct Node *next; 
    struct Node *prev;
} Node;

typedef Node *dcll;

void init(dcll *rootptr);
void insert(dcll *rootptr, const char *str);
void insert_beginning(dcll *rootptr,  const char *str);
void insert_ending(dcll *rootptr, const char *str);
void delete_beginning(dcll *rootptr);
void delete_ending(dcll *rootptr);
void display_clockwise(dcll rootptr);
void display_counter_clockwise(dcll rootptr);
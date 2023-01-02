
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef Node *ll;

void init(ll *rootptr);
void create(ll *rootptr, int n);  
void display(ll rootptr);  
void delNode(ll *rootptr, int n);
ll search(ll rootptr, int n);
typedef struct Node Node;

struct Node {
    void* key;
    void* value;

    Node* left;
    Node* right;
    Node* parent;
};


typedef struct Tree {
    Node* root;
    int (*compare_keys)(void*, void*);
    void (*destroy_node_hook)(Node*);
} Tree;


typedef enum Order {
    PREFIX,
    INFIX,
    POSTFIX
} Order;


void tree_init(
    Tree* tree,
    int (*compare_keys)(void*, void*), 
    void (*destroy_node_hook)(Node*)
);

void tree_destroy(Tree* tree);
void tree_insert(Tree* tree, void* key, void* value);
void* tree_lookup(Tree* tree, void* key);
void tree_remove(Tree* tree, void* key);

void default_destroy_node_hook(Node* node);

void tree_traverse(
    Tree* tree,
    void (*visit_node)(Node*),
    Order order
);

void bfs(Tree* tree, void (*visit_node)(Node*));
void dfs(Tree* tree, void (*visit_node)(Node*));

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* sibling;
    struct node* child;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->sibling = NULL;
    new_node->child = NULL;
    return new_node;
}

void add_child(struct node* parent, struct node* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        struct node* sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void print_tree(struct node* node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%d\n", node->data);
    print_tree(node->child, depth + 1);
    print_tree(node->sibling, depth);
}

int main() {
    struct node* root = create_node(1);
    add_child(root, create_node(2));
    add_child(root, create_node(3));
    struct node* child1 = create_node(4);
    add_child(child1, create_node(5));
    add_child(child1, create_node(6));
    add_child(root, child1);
    struct node* child2 = create_node(7);
    add_child(child2, create_node(8));
    add_child(child2, create_node(9));
    add_child(root, child2);
    print_tree(root, 0);
    return 0;
}

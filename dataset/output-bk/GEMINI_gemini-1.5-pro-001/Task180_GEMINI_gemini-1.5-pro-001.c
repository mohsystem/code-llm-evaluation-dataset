#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node* parent;
  struct Node** children;
  int num_children;
} Node;

Node* create_node(int val) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->val = val;
  node->parent = NULL;
  node->children = NULL;
  node->num_children = 0;
  return node;
}

void add_child(Node* parent, Node* child) {
  parent->num_children++;
  parent->children = (Node**)realloc(parent->children, parent->num_children * sizeof(Node*));
  parent->children[parent->num_children - 1] = child;
  child->parent = parent;
}

Node* find_node(Node* root, int val) {
  if (root->val == val) {
    return root;
  }
  for (int i = 0; i < root->num_children; i++) {
    Node* found = find_node(root->children[i], val);
    if (found) {
      return found;
    }
  }
  return NULL;
}

void reparent_tree(Node* root, int new_root_val) {
  Node* new_root = find_node(root, new_root_val);
  if (!new_root) {
    return;
  }

  if (new_root->parent) {
    // Remove new_root from its old parent's children list
    for (int i = 0; i < new_root->parent->num_children; i++) {
      if (new_root->parent->children[i] == new_root) {
        for (int j = i; j < new_root->parent->num_children - 1; j++) {
          new_root->parent->children[j] = new_root->parent->children[j + 1];
        }
        new_root->parent->num_children--;
        break;
      }
    }
    new_root->parent = NULL;
  }

  // Connect old root as a child of new_root
  if (root != new_root) {
    add_child(new_root, root);
  }
}

void print_tree(Node* root, int level) {
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  printf("%d
", root->val);
  for (int i = 0; i < root->num_children; i++) {
    print_tree(root->children[i], level + 1);
  }
}

int main() {
  // Create the initial tree
  Node* node0 = create_node(0);
  Node* node1 = create_node(1);
  Node* node2 = create_node(2);
  Node* node3 = create_node(3);
  Node* node4 = create_node(4);
  Node* node5 = create_node(5);
  Node* node6 = create_node(6);
  Node* node7 = create_node(7);
  Node* node8 = create_node(8);
  Node* node9 = create_node(9);

  add_child(node0, node1);
  add_child(node0, node2);
  add_child(node0, node3);
  add_child(node1, node4);
  add_child(node1, node5);
  add_child(node2, node6);
  add_child(node2, node7);
  add_child(node3, node8);
  add_child(node3, node9);

  printf("Original tree:
");
  print_tree(node0, 0);

  // Reparent the tree
  reparent_tree(node0, 6);

  printf("
Reparented tree:
");
  print_tree(node6, 0);

  return 0;
}
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BinarySearchTree {
public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int data) {
    Node *newNode = new Node(data);
    if (root == nullptr) {
      root = newNode;
      return;
    }
    Node *current = root;
    while (true) {
      if (data < current->data) {
        if (current->left == nullptr) {
          current->left = newNode;
          return;
        }
        current = current->left;
      } else {
        if (current->right == nullptr) {
          current->right = newNode;
          return;
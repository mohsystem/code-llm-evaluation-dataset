#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

struct Node* deleteNode(struct Node* node, int data) {
    if (node == NULL) {
        return node;
    }
    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    } else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    } else {
        if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        node->data = minValue(node->right);
        node->right = deleteNode(node->right, node->data);
    }
    return node;
}

int minValue(struct Node* node) {
    int minv = node->data;
    while (node->left != NULL) {
        minv = node->left->data;
        node = node->left;
    }
    return minv;
}

bool search(struct Node* node, int data) {
    if (node == NULL) {
        return false;
    }
    if (data == node->data) {
        return true;
    }
    if (data < node->data) {
        return search(node->left, data);
    }
    return search(node->right, data);
}

void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* temp;
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left != NULL) {
            queue[rear++] = temp->left;
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right;
        }
    }
    free(queue);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("
");

    printf("Search for 40: %d
", search(root, 40));
    printf("Search for 100: %d
", search(root, 100));

    printf("
Delete 20
");
    root = deleteNode(root, 20);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("
");

    printf("Delete 50
");
    root = deleteNode(root, 50);
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("
");

    return 0;
}
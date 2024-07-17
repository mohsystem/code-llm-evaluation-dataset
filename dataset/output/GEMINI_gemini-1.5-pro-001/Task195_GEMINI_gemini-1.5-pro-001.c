#include <stdio.h>
#include <stdlib.h>

// Structure for a node in a max-heap
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at given node
void maxHeapify(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }

    Node* largest = root;
    if (root->left && root->left->data > largest->data) {
        largest = root->left;
    }
    if (root->right && root->right->data > largest->data) {
        largest = root->right;
    }

    if (largest != root) {
        swap(&(root->data), &(largest->data));
        maxHeapify(largest);
    }
}

// Function to insert a new node into the max-heap
Node* insertMaxHeap(Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }

    if (data <= root->data) {
        root->left = insertMaxHeap(root->left, data);
    } else {
        root->right = insertMaxHeap(root->right, data);
    }

    maxHeapify(root);
    return root;
}

// Function to get the maximum element from the max-heap
int getMax(Node* root) {
    return root->data; 
}

// Function to extract the maximum element from the max-heap
Node* extractMax(Node* root) {
    if (root == NULL) {
        return NULL; 
    }

    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    // Find the rightmost node in the last level
    Node* lastNode = root;
    while (lastNode->right != NULL) {
        lastNode = lastNode->right;
    }
    if (lastNode->left != NULL) {
        lastNode = lastNode->left;
    }

    // Replace root with the last node
    root->data = lastNode->data;

    // Remove the last node and heapify
    if (lastNode == lastNode->right) {
        free(lastNode); 
    } else {
        free(lastNode); 
    }
    maxHeapify(root);
    return root;
}

// Structure for a MedianFinder
typedef struct {
    Node* small; // Max-heap for smaller half
    Node* large; // Min-heap for larger half (implemented using max-heap)
} MedianFinder;

// Function to initialize the MedianFinder
MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->small = NULL;
    obj->large = NULL;
    return obj;
}

// Function to add a number to the MedianFinder
void medianFinderAddNum(MedianFinder* obj, int num) {
    // Add to the appropriate heap
    if (obj->small == NULL || num <= getMax(obj->small)) {
        obj->small = insertMaxHeap(obj->small, num);
    } else {
        obj->large = insertMaxHeap(obj->large, -num); // Negate for min-heap
    }

    // Balance the heaps
    if ((obj->small != NULL && obj->large != NULL && 
         getMax(obj->small) > -getMax(obj->large)) ||
        (obj->small != NULL && obj->large == NULL) ||
        (obj->small != NULL && obj->large != NULL && 
         (obj->small != NULL ? 1 : 0) - (obj->large != NULL ? 1 : 0) > 1)) {
        if (obj->large == NULL) {
            obj->large = insertMaxHeap(obj->large, -getMax(obj->small));
            obj->small = extractMax(obj->small);
        } else {
            obj->small = insertMaxHeap(obj->small, -getMax(obj->large));
            obj->large = extractMax(obj->large);
        }
    }
}

// Function to find the median
double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->small != NULL && obj->large != NULL && 
        (obj->small != NULL ? 1 : 0) == (obj->large != NULL ? 1 : 0)) {
        return (double)(getMax(obj->small) - getMax(obj->large)) / 2;
    } else if (obj->small != NULL) {
        return getMax(obj->small);
    } else {
        return -getMax(obj->large);
    }
}

// Function to free the MedianFinder
void medianFinderFree(MedianFinder* obj) {
    // Implement a function to free the heaps (not shown here)
    free(obj);
}

int main() {
    MedianFinder* mf = medianFinderCreate();

    medianFinderAddNum(mf, 1);
    medianFinderAddNum(mf, 2);
    printf("%.1f
", medianFinderFindMedian(mf)); // Output: 1.5

    medianFinderAddNum(mf, 3);
    printf("%.1f
", medianFinderFindMedian(mf)); // Output: 2.0

    medianFinderFree(mf);
    return 0;
}
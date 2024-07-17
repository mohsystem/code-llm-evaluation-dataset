#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

typedef struct {
    char node;
    int weight;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} Graph;

Graph graph[MAX_NODES];
int distances[MAX_NODES];

void dijkstra(char start) {
    for (int i = 0; i < MAX_NODES; i++) {
        distances[i] = INT_MAX;
    }
    distances[start - 'A'] = 0;
    Node* pq[MAX_NODES];
    int pq_size = 0;
    pq[pq_size++] = (Node*)malloc(sizeof(Node));
    pq[pq_size - 1]->node = start;
    pq[pq_size - 1]->weight = 0;
    pq[pq_size - 1]->next = NULL;
    while (pq_size > 0) {
        Node* current = pq[--pq_size];
        Node* neighbor = graph[current->node - 'A'].head;
        while (neighbor != NULL) {
            if (current->weight + neighbor->weight < distances[neighbor->node - 'A']) {
                distances[neighbor->node - 'A'] = current->weight + neighbor->weight;
                Node* new_node = (Node*)malloc(sizeof(Node));
                new_node->node = neighbor->node;
                new_node->weight = distances[neighbor->node - 'A'];
                new_node->next = NULL;
                pq[pq_size++] = new_node;
            }
            neighbor = neighbor->next;
        }
        free(current);
    }
}

int main() {
    graph['A' - 'A'].head = (Node*)malloc(sizeof(Node));
    graph['A' - 'A'].head->node = 'B';
    graph['A' - 'A'].head->weight = 1;
    graph['A' - 'A'].head->next = (Node*)malloc(sizeof(Node));
    graph['A' - 'A'].head->next->node = 'C';
    graph['A' - 'A'].head->next->weight = 4;
    graph['A' - 'A'].head->next->next = NULL;

    graph['B' - 'A'].head = (Node*)malloc(sizeof(Node));
    graph['B' - 'A'].head->node = 'A';
    graph['B' - 'A'].head->weight = 1;
    graph['B' - 'A'].head->next = (Node*)malloc(sizeof(Node));
    graph['B' - 'A'].head->next->node = 'C';
    graph['B' - 'A'].head->next->weight = 2;
    graph['B' - 'A'].head->next->next = (Node*)malloc(sizeof(Node));
    graph['B' - 'A'].head->next->next->node = 'D';
    graph['B' - 'A'].head->next->next->weight = 5;
    graph['B' - 'A'].head->next->next->next = NULL;

    graph['C' - 'A'].head = (Node*)malloc(sizeof(Node));
    graph['C' - 'A'].head->node = 'A';
    graph['C' - 'A'].head->weight = 4;
    graph['C' - 'A'].head->next = (Node*)malloc(sizeof(Node));
    graph['C' - 'A'].head->next->node = 'B';
    graph['C' - 'A'].head->next->weight = 2;
    graph['C' - 'A'].head->next->next = (Node*)malloc(sizeof(Node));
    graph['C' - 'A'].head->next->next->node = 'D';
    graph['C' - 'A'].head->next->next->weight = 1;
    graph['C' - 'A'].head->next->next->next = NULL;

    graph['D' - 'A'].head = (Node*)malloc(sizeof(Node));
    graph['D' - 'A'].head->node = 'B';
    graph['D' - 'A'].head->weight = 5;
    graph['D' - 'A'].head->next = (Node*)malloc(sizeof(Node));
    graph['D' - 'A'].head->next->node = 'C';
    graph['D' - 'A'].head->next->weight = 1;
    graph['D' - 'A'].head->next->next = NULL;

    for (char c = 'A'; c <= 'D'; c++) {
        distances[c - 'A'] = INT_MAX;
    }

    char startNode = 'A';
    dijkstra(startNode);

    for (char c = 'A'; c <= 'D'; c++) {
        printf("%c: %d
", c, distances[c - 'A']);
    }

    return 0;
}
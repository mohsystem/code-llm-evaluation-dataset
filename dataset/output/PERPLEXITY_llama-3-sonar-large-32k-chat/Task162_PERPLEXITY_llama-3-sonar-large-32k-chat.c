// C does not support priority queue and unordered map out of the box, so we will use a simple array and a linear search to implement Dijkstra's algorithm.

#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    char name;
    int distance;
} Node;

typedef struct {
    char from;
    char to;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int edgeCount = 0;

Node nodes[MAX_NODES];
int nodeCount = 0;

void addNode(char name) {
    nodes[nodeCount].name = name;
    nodes[nodeCount].distance = INT_MAX;
    nodeCount++;
}

void addEdge(char from, char to, int weight) {
    edges[edgeCount].from = from;
    edges[edgeCount].to = to;
    edges[edgeCount].weight = weight;
    edgeCount++;
}

void dijkstra(char start) {
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i].name == start) {
            nodes[i].distance = 0;
            break;
        }
    }

    for (int i = 0; i < nodeCount; i++) {
        int minDistance = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < nodeCount; j++) {
            if (nodes[j].distance < minDistance) {
                minDistance = nodes[j].distance;
                minIndex = j;
            }
        }

        for (int j = 0; j < edgeCount; j++) {
            if (edges[j].from == nodes[minIndex].name) {
                int distance = nodes[minIndex].distance + edges[j].weight;
                for (int k = 0; k < nodeCount; k++) {
                    if (nodes[k].name == edges[j].to && distance < nodes[k].distance) {
                        nodes[k].distance = distance;
                    }
                }
            }
        }
    }

    for (int i = 0; i < nodeCount; i++) {
        printf("%c: %d\n", nodes[i].name, nodes[i].distance);
    }
}

int main() {
    addNode('A');
    addNode('B');
    addNode('C');
    addNode('D');

    addEdge('A', 'B', 1);
    addEdge('A', 'C', 4);
    addEdge('B', 'A', 1);
    addEdge('B', 'C', 2);
    addEdge('B', 'D', 5);
    addEdge('C', 'A', 4);
    addEdge('C', 'B', 2);
    addEdge('C', 'D', 1);
    addEdge('D', 'B', 5);
    addEdge('D', 'C', 1);

    dijkstra('A');
    return 0;
}
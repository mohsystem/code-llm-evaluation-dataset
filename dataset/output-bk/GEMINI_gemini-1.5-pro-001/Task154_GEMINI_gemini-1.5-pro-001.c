#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Stack implementation
struct Stack {
    int top;
    int items[MAX_VERTICES];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    stack->items[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1; // Stack underflow
    }
    return stack->items[stack->top--];
}

void depthFirstSearch(struct Graph* graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    struct Stack* stack = createStack();

    push(stack, startVertex);

    while (!isEmpty(stack)) {
        int vertex = pop(stack);

        if (!visited[vertex]) {
            visited[vertex] = true;
            printf("%d ", vertex); // Process the vertex here

            // Push all adjacent vertices onto the stack
            for (int i = graph->numVertices - 1; i >= 0; i--) {
                if (graph->adjMatrix[vertex][i] && !visited[i]) {
                    push(stack, i);
                }
            }
        }
    }
}

int main() {
    struct Graph graph = {
        6, // Number of vertices
        {
            {0, 1, 1, 0, 0, 0},
            {1, 0, 0, 1, 1, 0},
            {1, 0, 0, 0, 0, 1},
            {0, 1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 1},
            {0, 0, 1, 0, 1, 0}
        } // Adjacency matrix representation of the graph
    };

    int startVertex = 0; // Starting vertex for DFS

    printf("Depth First Traversal (starting from vertex %d): ", startVertex);
    depthFirstSearch(&graph, startVertex);

    return 0;
}
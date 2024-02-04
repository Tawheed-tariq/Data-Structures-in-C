#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    struct Node* adjacencyList[MAX];
    int visited[MAX];
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    int i;
    for (i = 0; i < MAX; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    // For undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void BFS(struct Graph* graph, int startNode) {
    int queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = startNode;
    graph->visited[startNode] = 1;

    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d ", currentNode);

        struct Node* temp = graph->adjacencyList[currentNode];
        while (temp != NULL) {
            int adjNode = temp->data;
            if (graph->visited[adjNode] == 0) {
                queue[rear++] = adjNode;
                graph->visited[adjNode] = 1;
            }
            temp = temp->next;
        }
    }
}
int main() {
    struct Graph* graph = createGraph();
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    printf("Breadth-First Traversal starting from node 0: ");
    BFS(graph, 0);
    printf("\n");
    return 0;
}
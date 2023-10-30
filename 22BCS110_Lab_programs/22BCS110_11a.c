#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100
typedef struct {
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
    } else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
    }
    return item;
}

typedef struct {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;

    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

void bfs(Graph* g, int startVertex) {
    
    bool visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }

    
    Queue q;
    initQueue(&q);
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    printf("BFS traversal: ");

    while (!isEmpty(&q)) {
        
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);

        
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    Graph g;
    int vertices, edges, src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &src, &dest);
        addEdge(&g, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(&g, startVertex);

    return 0;
}
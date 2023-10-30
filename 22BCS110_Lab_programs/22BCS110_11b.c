#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 20
struct {
    int vertices;
    int adjMatrix[MAX_NODES][MAX_NODES];
}typedef Graph;

void initGraph(Graph* g, int vertices) {
    g->vertices = vertices;
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < MAX_NODES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;
}

void dfsRecursive(Graph* g, int currentVertex, bool visited[]) {
    visited[currentVertex] = true;
    printf("%d ", currentVertex);
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
            dfsRecursive(g, i, visited);
        }
    }
}

void dfs(Graph* g, int startVertex) {
    bool visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }
    printf("DFS traversal: ");
    dfsRecursive(g, startVertex, visited);
}

int main() {
    Graph g;
    int vertices, edges, start, end;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (source and endination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &start, &end);
        addEdge(&g, start, end);
    }
    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);
    dfs(&g, startVertex);
    return 0;
}
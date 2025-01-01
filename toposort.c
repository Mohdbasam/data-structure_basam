#include <stdio.h>

#define MAX_VERTICES 100

int adj[MAX_VERTICES][MAX_VERTICES], in_degree[MAX_VERTICES], num_vertices;

int main() {
    int edges, u, v, queue[MAX_VERTICES], front = 0, rear = 0, top_order[MAX_VERTICES], index = 0;

    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        in_degree[i] = 0;
        for (int j = 0; j < num_vertices; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges in the format (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        in_degree[v]++;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front != rear) {
        int vertex = queue[front++];
        top_order[index++] = vertex;

        for (int i = 0; i < num_vertices; i++) {
            if (adj[vertex][i] == 1) {
                in_degree[i]--;
                if (in_degree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (index != num_vertices) {
        printf("There is a cycle in the graph.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < num_vertices; i++) {
            printf("%d ", top_order[i]);
        }
        printf("\n");
    }

    return 0;
}

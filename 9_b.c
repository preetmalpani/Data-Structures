#include <stdio.h>

int adj[20][20], visited[20], n;

void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start = 0, connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(start);

    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is CONNECTED\n");
    else
        printf("The graph is NOT CONNECTED\n");

    return 0;
}
OUTPUT:
Enter number of vertices: 3
Enter adjacency matrix:
0
1
1
0
0
1
0
1
0
The graph is CONNECTED

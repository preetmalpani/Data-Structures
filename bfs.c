#include <stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20], adj[20][20], n;

void enqueue(int v) {
    if (rear == n - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start) {
    int i, v;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

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

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}

OUTPUT:
Enter number of vertices: 4
Enter adjacency matrix:
0
0
1
1
0
0
1
1
1
1
0
0
1
0
1
0
Enter starting vertex: 0
BFS Traversal: 0 2 3 1
Process returned 0 (0x0)   execution time : 35.026 s
Press any key to continue.

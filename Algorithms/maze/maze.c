#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_QUEUE_SIZE 10000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p;
    int dist;
} Node;

Node priorityQueue[MAX_QUEUE_SIZE];
int queueSize = 0;

void push(Node node) {
    priorityQueue[queueSize++] = node;
}

Node pop() {
    int minIdx = 0;
    for (int i = 1; i < queueSize; i++) {
        if (priorityQueue[i].dist < priorityQueue[minIdx].dist) {
            minIdx = i;
        }
    }
    Node minNode = priorityQueue[minIdx];
    priorityQueue[minIdx] = priorityQueue[--queueSize];
    return minNode;
}

bool isValid(int x, int y, int m, int n, char room[MAX_ROWS][MAX_COLS]) {
    return x >= 0 && x < m && y >= 0 && y < n && room[x][y] != '#';
}

int dijkstra(char room[MAX_ROWS][MAX_COLS], int m, int n, Point start, Point end) {
    int dist[MAX_ROWS][MAX_COLS];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Initialize distance array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }

    dist[start.x][start.y] = 0;
    push((Node){start, 0});

    while (queueSize > 0) {
        Node current = pop();
        int x = current.p.x;
        int y = current.p.y;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x;
            int ny = y;
            int tiles_moved = 0;
            
            // Slide in current direction until hitting a wall
            while (true) {
                int nextX = nx + dx[dir];
                int nextY = ny + dy[dir];
                
                if (!isValid(nextX, nextY, m, n, room)) {
                    break;
                }
                nx = nextX;
                ny = nextY;
                tiles_moved++;
            }

            // Add all tiles moved during this slide
            if (tiles_moved > 0) {
                long newDist = dist[x][y] + tiles_moved;
                if (newDist < dist[nx][ny]) {
                    dist[nx][ny] = newDist;
                    push((Node){(Point){nx, ny}, newDist});
                }
            }
        }
    }

    if (dist[end.x][end.y] != INT_MAX) {
        return dist[end.x][end.y];
    } else {
        return -1;
    }
}

int main() {
    FILE* file = fopen("ROOMS.txt", "r");
    if (!file) {
        printf("Error opening file!\n");
        return 1;
    }

    int m, n;
    char room[MAX_ROWS][MAX_COLS];
    Point start, end;

    while (fscanf(file, "%d %d", &m, &n) == 2) {
        // Reset queue for each test case
        queueSize = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                fscanf(file, " %c", &room[i][j]);
                if (room[i][j] == 'S') {
                    start.x = i;
                    start.y = j;
                } else if (room[i][j] == 'C') {
                    end.x = i;
                    end.y = j;
                }
            }
        }

        long result = dijkstra(room, m, n, start, end);
        if (result == -1) {
            printf("No path found from S to C.\n");
        } else {
            printf("Shortest Path: %ld\n", result);
        }
    }

    fclose(file);
    return 0;
}
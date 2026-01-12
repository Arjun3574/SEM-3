//Title: Assignment-2
//Topic: Extension
//Name: Arjun Mankuskar
//PRN: 202401110038
// Deadlock Detection and Avoidance
// Objective: Learn strategies for handling deadlocks in OS.
//Extension: Modify the program to detect deadlock using a wait-for graph.
// Deliverable: Submit the implementation, test cases, and analysis of results.

// 1. C Code
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX], visited[MAX], recStack[MAX];
int p;

bool dfs(int v) {
    visited[v] = recStack[v] = 1;
    for (int i = 0; i < p; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[v] = 0;
    return false;
}

bool detect_deadlock() {
    for (int i = 0; i < p; i++) {
        visited[i] = recStack[i] = 0;
    }
    for (int i = 0; i < p; i++) {
        if (!visited[i] && dfs(i))
            return true;
    }
    return false;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &p);

    printf("Enter Wait-For Graph adjacency matrix:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &graph[i][j]);

    if (detect_deadlock())
        printf("\nDeadlock detected in the system.\n");
    else
        printf("\nNo deadlock detected. System is safe.\n");

    return 0;
}

// 2. Output
/*
Safe State:
Enter number of processes: 4
Enter Wait-For Graph adjacency matrix:
0 1 0 0
0 0 1 0
0 0 0 0
0 0 0 0

No deadlock detected. System is safe.

---------------------------------

Unsafe state:
Enter number of processes: 4
Enter Wait-For Graph adjacency matrix:
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0

Deadlock detected in the system.
*/

//3. Analysis
/*
    The implementation of the Bankerâ€™s Algorithm identifies whether 
the system is in a safe state or unsafe state based on current 
allocation, maximum demands, nad available resources. In safe 
scenarios, the algorithm produces a valid safe sequence, ensuring 
all processes can complete without deadlock. In unsafe cases, it 
correctly flags the risk of deadlock due to insufficient resources 
to satisfy any process.
    The extension using a wait-for graph effectively detects
deadlocks by identifying cycles in process dependencies. If a cycle 
exists, it indicates that processes are waiting on each other
indefinitely, confirming a deadlock. If no cycle is found,the
system is safe.
    Together, these simulations demonstrate how deadlock avoidance 
(Banker's Algorithm) and deadlock detection (wait-for graph) 
complement each other in managing resource allocation and system 
stability.
*/
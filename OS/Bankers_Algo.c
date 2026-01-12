//Title: Assignment-2
//Topic: Banker's Algorithm
//Name: Arjun Mankuskar
//PRN: 202401110038
// Deadlock Detection and Avoidance
// Objective: Learn strategies for handling deadlocks in OS.
// Task:
// Implement a program in C/Java to simulate Bankerâ€™s Algorithm for deadlock avoidance.
// Input: number of processes, resources, allocation, and maximum demand matrices.
// Output: safe sequence (if exists) or report that the system is in unsafe state.

//1. C Code
#include <stdio.h>
#include <stdbool.h>

#define MAX_P 10
#define MAX_R 10

int n, m;
int alloc[MAX_P][MAX_R], max[MAX_P][MAX_R], need[MAX_P][MAX_R];
int avail[MAX_R];

void calculate_need() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j]; 
}

bool is_safe() {
    int work[MAX_R];
    bool finish[MAX_P] = {false};
    int safe_seq[MAX_P], count = 0;

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool can_run = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        can_run = false;
                        break;
                    }
                }
                if (can_run) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    safe_seq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in an UNSAFE state. Deadlock may occur.\n");
            return false;
        }
    }

    printf("\nSystem is in a SAFE state.\nSafe sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safe_seq[i]);
    printf("\n");
    return true;
}

int main() {
    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Demand Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    calculate_need();
    is_safe();

    return 0;
}


//2. Output
/*
Safe State:
Enter number of processes and resources: 5 3
Enter Allocation Matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter Maximum Demand Matrix:
7 5 3
3 2 2
9 0 2
4 2 2
5 3 3
Enter Available Resources:
3 3 2

System is in a SAFE state.
Safe sequence: P1 P3 P4 P0 P2 

-----------------------------

Unsafe State:
Enter number of processes and resources: 3 3 
Enter Allocation Matrix:
0 1 0
2 0 0
3 0 3
Enter Maximum Demand Matrix:
7 5 3
3 2 2
9 0 4
Enter Available Resources:
0 2 0

System is in an UNSAFE state. Deadlock may occur.
*/

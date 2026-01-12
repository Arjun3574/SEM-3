//Title: Assignment-1
//Topic: CPU Scheduling
//Name: Arjun Mankuskar
//PRN: 202401110038
//Process Scheduling Simulation
// Objective: Apply CPU scheduling algorithms to analyze efficiency.
// Task: Write a CPP program to simulate FCFS, SJF, and Round Robin scheduling.
// Input: process IDs, arrival times, burst times, and time quantum (for RR).
// Output: Gantt chart, turnaround time (TAT), waiting time (WT), and average values.
//Deliverable: Compare scheduling outcomes and recommend the best for different workload types (batch vs. interactive jobs).


//1. C++ Code
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    int pid, arrival, burst, remaining, start, finish;
    int tat, wt;
};

void printMetrics(const vector<Process>& pList) {
    float totalTAT = 0, totalWT = 0;
    cout << "\nPID\tArrival\tBurst\tStart\tFinish\tTAT\tWT\n";
    for (const auto& p : pList) {
        cout << p.pid << "\t" << p.arrival << "\t" << p.burst << "\t" << p.start
             << "\t" << p.finish << "\t" << p.tat << "\t" << p.wt << "\n";
        totalTAT += p.tat;
        totalWT += p.wt;
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage TAT: " << totalTAT / pList.size();
    cout << "\nAverage WT : " << totalWT / pList.size() << "\n";
}

void FCFS(vector<Process> pList) {
    cout << "\n--- FCFS Scheduling ---\nGantt Chart:\n";
    sort(pList.begin(), pList.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int time = 0;
    for (auto& p : pList) {
        time = max(time, p.arrival);
        p.start = time;
        time += p.burst;
        p.finish = time;
        p.tat = p.finish - p.arrival;
        p.wt = p.start - p.arrival;
        cout << "| P" << p.pid << " ";
    }
    cout << "|\n";
    printMetrics(pList);
}

void SJF(vector<Process> pList) {
    cout << "\n--- SJF Scheduling ---\nGantt Chart:\n";
    int time = 0, completed = 0;
    vector<Process> result;
    while (completed < pList.size()) {
        vector<Process*> ready;
        for (auto& p : pList)
            if (p.arrival <= time && p.remaining > 0)
                ready.push_back(&p);

        if (ready.empty()) {
            time++;
            continue;
        }

        auto shortest = *min_element(ready.begin(), ready.end(), [](Process* a, Process* b) {
            return a->burst < b->burst;
        });

        shortest->start = time;
        time += shortest->burst;
        shortest->finish = time;
        shortest->tat = shortest->finish - shortest->arrival;
        shortest->wt = shortest->start - shortest->arrival;
        shortest->remaining = 0;
        result.push_back(*shortest);
        completed++;
        cout << "| P" << shortest->pid << " ";
    }
    cout << "|\n";
    printMetrics(result);
}

void RoundRobin(vector<Process> pList, int quantum) {
    cout << "\n--- Round Robin Scheduling (Q=" << quantum << ") ---\nGantt Chart:\n";
    queue<Process*> q;
    int time = 0;
    vector<Process> result;
    sort(pList.begin(), pList.end(), [](Process a, Process b) {
        return a.arrival < b.arrival;
    });

    int idx = 0;
    while (idx < pList.size() && pList[idx].arrival <= time)
        q.push(&pList[idx++]);

    while (!q.empty()) {
        Process* p = q.front(); q.pop();
        if (p->remaining == p->burst)
            p->start = time;

        int execTime = min(quantum, p->remaining);
        cout << "| P" << p->pid << " ";
        time += execTime;
        p->remaining -= execTime;

        while (idx < pList.size() && pList[idx].arrival <= time)
            q.push(&pList[idx++]);

        if (p->remaining > 0)
            q.push(p);
        else {
            p->finish = time;
            p->tat = p->finish - p->arrival;
            p->wt = p->tat - p->burst;
            result.push_back(*p);
        }
    }
    cout << "|\n";
    printMetrics(result);
}

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> pList(n);
    cout << "Enter Process ID, Arrival Time, Burst Time:\n";
    for (int i = 0; i < n; ++i) {
        cin >> pList[i].pid >> pList[i].arrival >> pList[i].burst;
        pList[i].remaining = pList[i].burst;
    }
    cout << "Enter Time Quantum for Round Robin: ";
    cin >> quantum;

    FCFS(pList);
    SJF(pList);
    RoundRobin(pList, quantum);

    return 0;
}


//2. Output: 
/*
Enter number of processes: 4
Enter Process ID, Arrival Time, Burst Time:
1 0 5
2 1 3
3 2 8
4 3 6
Enter Time Quantum for Round Robin: 3

--- FCFS Scheduling ---
Gantt Chart:
| P1 | P2 | P3 | P4 |

PID     Arrival Burst   Start   Finish  TAT     WT
1       0       5       0       5       5       0
2       1       3       5       8       7       4
3       2       8       8       16      14      6
4       3       6       16      22      19      13

Average TAT: 11.25
Average WT : 5.75

--- SJF Scheduling ---
Gantt Chart:
| P1 | P2 | P4 | P3 |

PID     Arrival Burst   Start   Finish  TAT     WT
1       0       5       0       5       5       0
2       1       3       5       8       7       4
4       3       6       8       14      11      5
3       2       8       14      22      20      12

Average TAT: 10.75
Average WT : 5.25

--- Round Robin Scheduling (Q=3) ---
Gantt Chart:
| P1 | P2 | P3 | P4 | P1 | P3 | P4 | P3 |

PID     Arrival Burst   Start   Finish  TAT     WT
2       1       3       3       6       5       2
1       0       5       0       14      14      9
4       3       6       9       20      17      11
3       2       8       6       22      20      12

Average TAT: 14.00
Average WT : 8.50
*/

//3. Scheduling Algorithm Comparison
/*
Algorithm  	  Avg wait time	      Avg turn around time	 Fairness	 Best for
FCFS    	  Moderate to high	  Moderate	             Low	     Simple batch processing
SJF	          Lowest	          Lowest	             Low	     Batch jobs with predictable duration 
Round Robin	  Moderate to high	  Moderate	             High	     Interactive systems

ïƒ¼FCFS is simple but it can suffer when short jobs wait behind long jobs.
ïƒ¼SJF has less average wait time and turnaround time, but it can cause starvation for longer processes.
ïƒ¼Round Robin uses time slices to cycle through processes, ensuring no jobs wait for too long which makes
 it ideal for time sharing systems.
*/

//4. Recommendation
/*
ïƒ¼Batch Jobs: 
The SJF Algorithm is recommended for Batch Jobs because Batch jobs are typically non interactive and can 
be optimized for throughput. SJF minimizes average waiting time and turnaround time, making it ideal for 
maximizing efficiency.

ïƒ¼Interactive Jobs:
The Round Robin Algorithm is recommended here because Interactive systems require responsiveness. The 
Round Robin Algorithm ensures each process gets CPU time regularly, preventing any single process from 
monopolizing the CPU and keeping the system responsive to user input.
*/
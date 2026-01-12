//Title: Assignment-3
//Topic: Memory Management & Page Replacement
//Name: Arjun Mankuskar
//PRN: 202401110038
// Memory Management & Page Replacement
// Objective: Explore paging and memory optimization strategies.
// Task: Implement a simulation of page replacement algorithms (FIFO, LRU, Optimal) in CPP
// Input: reference string, number of frames.
// Output: page faults for each algorithm and a comparison chart.
// Deliverable: Analyze which algorithm is more suitable for workloads with large datasets.

#include <bits/stdc++.h>
using namespace std;

// ========== FIFO ==========
int fifo(vector<int> ref, int frames) {
    queue<int> q;
    unordered_set<int> s;
    int faults = 0;

    for (int page : ref) {
        if (s.find(page) == s.end()) {
            faults++;
            if (s.size() == frames) {
                int old = q.front();
                q.pop();
                s.erase(old);
            }
            s.insert(page);
            q.push(page);
        }
    }
    return faults;
}

// ========== LRU ==========
int lru(vector<int> ref, int frames) {
    list<int> l;
    unordered_map<int, list<int>::iterator> pos;
    int faults = 0;

    for (int page : ref) {
        if (pos.find(page) == pos.end()) {
            faults++;
            if ((int)l.size() == frames) {
                int last = l.back();
                l.pop_back();
                pos.erase(last);
            }
            l.push_front(page);
            pos[page] = l.begin();
        } else {
            l.erase(pos[page]);
            l.push_front(page);
            pos[page] = l.begin();
        }
    }
    return faults;
}

// ========== OPTIMAL ==========
int optimal(vector<int> ref, int frames) {
    vector<int> f;
    int faults = 0;

    for (int i = 0; i < ref.size(); i++) {
        if (find(f.begin(), f.end(), ref[i]) != f.end())
            continue;

        faults++;
        if (f.size() < frames) {
            f.push_back(ref[i]);
        } else {
            int farthest = -1, index = -1;
            for (int j = 0; j < frames; j++) {
                int next = -1;
                for (int k = i + 1; k < ref.size(); k++) {
                    if (ref[k] == f[j]) {
                        next = k;
                        break;
                    }
                }
                if (next == -1) {
                    index = j;
                    break;
                } else if (next > farthest) {
                    farthest = next;
                    index = j;
                }
            }
            f[index] = ref[i];
        }
    }
    return faults;
}

// ========== MAIN FUN ==========
int main() {
    int n, frames;
    cout << "Enter number of pages in reference string: ";
    cin >> n;

    vector<int> ref(n);
    cout << "Enter reference string: ";
    for (int i = 0; i < n; i++) cin >> ref[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    int fifo_f = fifo(ref, frames);
    int lru_f = lru(ref, frames);
    int opt_f = optimal(ref, frames);

    cout << "\n========== Page Fault Comparison ==========\n";
    cout << "FIFO     : " << fifo_f << endl;
    cout << "LRU      : " << lru_f << endl;
    cout << "Optimal  : " << opt_f << endl;

    cout << "\n========== Chart ==========\n";
    cout << "Algorithm\tPage Faults\n";
    cout << "FIFO\t\t" << fifo_f << "\n";
    cout << "LRU\t\t" << lru_f << "\n";
    cout << "Optimal\t\t" << opt_f << "\n";

    return 0;
}

/*
//Output:-
Enter number of pages in reference string: 12
Enter reference string: 1 2 3 2 1 4 5 2 1 3 4 5
Enter number of frames: 3

========== Page Fault Comparison ==========
FIFO     : 10
LRU      : 10
Optimal  : 7

========== Chart ==========
Algorithm       Page Faults
FIFO            10
LRU             10
Optimal         7


//Analysis: 
FIFO:-
The FIFO (First-In First-Out) page replacement algorithm is the simplest 
among the three. It replaces the oldest loaded page in memory without 
considering how frequently or recently the page has been used. Due to this 
rigid behavior, FIFO often performs poorly with large datasets, where memory 
access patterns are more complex and dynamic. A major drawback of FIFO is 
Beladyâ€™s Anomaly, where increasing the number of frames may unexpectedly 
increase page faults, making it unreliable for scalable workloads. Although 
FIFO is easy to implement, its lack of awareness about program locality and 
access behavior makes it unsuitable for applications that process large datasets
or require efficient memory utilization.

LRU:-
LRU (Least Recently Used) is designed around the idea that pages used recently 
are more likely to be used again soon. This algorithm tracks the history of page 
usage and replaces the page that has not been used for the longest time. Unlike 
FIFO, LRU aligns well with real-world memory access patterns because programs 
generally exhibit temporal locality, meaning they repeatedly access a small set 
of pages within short time intervals. As datasets grow larger, LRU continues to 
deliver stable and efficient performance because it adapts to changing access 
behavior. Although it requires more overhead to track page usage order, the 
improvement in page fault rates makes LRU a practical and effective choice for 
large-scale workloads and modern operating systems.

Optimal:-
The Optimal page replacement algorithm offers the best possible performance 
by replacing the page that will not be needed for the longest time in the
future. Since it relies on perfect future knowledge of memory accesses, it 
cannot be implemented in real systems but serves as a benchmark for comparing 
other algorithms. When applied to large datasets, Optimal consistently produces 
the lowest number of page faults because it makes ideal decisions with complete 
foresight. While it is the gold standard in theory, its practical use is limited 
to simulations and teaching concepts in operating system design. Nonetheless, 
Optimal provides valuable insight into the upper limit of efficiency that real 
world algorithms, such as LRU, attempt to approximate.
*/
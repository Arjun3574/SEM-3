#include <iostream>
using namespace std;

int heapArr[100];   // array to store heap
int heapSize = 0;   // current size

void heapifyUp(int index) {
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heapArr[parent] < heapArr[index]) {
            swap(heapArr[parent], heapArr[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int index) {
    while(true) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;

        if(left < heapSize && heapArr[left] > heapArr[largest])
            largest = left;
        if(right < heapSize && heapArr[right] > heapArr[largest])
            largest = right;

        if(largest != index) {
            swap(heapArr[index], heapArr[largest]);
            index = largest;
        } else break;
    }
}

void insertElement(int value) {
    heapArr[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

void deleteMax() {
    if(heapSize == 0) return;
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
}

int getMax() {
    if(heapSize > 0)
        return heapArr[0];
    return -1; // empty queue
}

int main() {
    insertElement(30);
    insertElement(10);
    insertElement(50);
    insertElement(40);

    cout << "Priority Queue (max first):\n";
    while(heapSize > 0) {
        cout << getMax() << " ";
        deleteMax();
    }
    return 0;
}

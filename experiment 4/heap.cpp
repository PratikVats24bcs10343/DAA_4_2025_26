#include <bits/stdc++.h>
using namespace std;
void heapifyUp(vector<int>& heap, int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}
void heapifyDown(vector<int>& heap, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(heap, n, smallest);
    }
}
void deleteAtIndex(vector<int>& heap, int i) {
    int n = heap.size();
    if (i >= n) {
        cout << "Invalid index\n";
        return;
    }
    heap[i] = heap[n - 1];
    heap.pop_back();

    if (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        heapifyUp(heap, i);
    } else {
        heapifyDown(heap, heap.size(), i);
    }
}
void printHeap(vector<int>& heap) {
    for (int x : heap)
        cout << x << " ";
    cout << endl;
}
int main() {
    vector<int> heap = {10, 20, 30, 40, 50};

    cout << "Heap : ";
    printHeap(heap);
    cout<<endl;

    int index = 1;
    deleteAtIndex(heap, index);

    cout << "after deleting" << index << " : ";
    printHeap(heap);
    cout<<endl;

    return 0;
}
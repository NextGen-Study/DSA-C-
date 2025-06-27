#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

public:
MaxHeap() {
    heap.push_back(-1);
    
}    void insert(int value) {
        heap.push_back(value);            // Step 1: Insert at the end
        int index = heap.size() - 1;
               // Step 2: Get index of inserted element

        // Step 3: Swap with parent while heap property is violated
        while (index > 1) {
            int parent = index / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void printHeap() {
        for (int o =1 ; o < heap.size(); o++) {
            cout << heap[o] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(50);

    cout << "Heap elements: ";
    h.printHeap();

    return 0;
}

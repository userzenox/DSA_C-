#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        // Percolate up
        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    void deleteRoot() {
        if(size == 0) {
            cout << "Heap is empty!" << endl;
            return;
        }
        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // Percolate down
        int index = 1;
        while(index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if(left <= size && arr[left] > arr[largest]) {
                largest = left;
            }
            if(right <= size && arr[right] > arr[largest]) {
                largest = right;
            }
            if(largest != index) {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    cout << "Heap after insertions:" << endl;
    h.print();

    h.deleteRoot();
    cout << "Heap after deleting root:" << endl;
    h.print();

    return 0;
}

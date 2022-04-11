#include <bits/stdc++.h>

using namespace std;
// re-writing heap

class MinHeap
{
private:
    int capacity;
    int *heapArray;
    int heap_size;
    int *parent();
    int *getLeftChild();
    int *getRightChild();
    bool hasLeftChild();
    bool hasRightChild();
    void MinifyHeap();

public:
    MinHeap(int capacity)
    {
        heap_size = 0;
        capacity = capacity;
        heapArray = ((int *)malloc(sizeof(int) * capacity));
    }
    int getMin();
    int extractMin();
    void insertKey();
    void deleteKey();
    void printArray()
    {
        for (int i = 0; i < heap_size; ++i)
        {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    };
    bool linearSearch(int value)
    {
        for (int i = 0; i < heap_size; ++i)
        {
            if (value == heapArray[i])
                return true;
        }
        return false;
    };
};

int main()
{
}
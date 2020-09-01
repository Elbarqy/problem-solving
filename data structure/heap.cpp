#include <bits/stdc++.h>

using namespace std;

class Heap
{
    int capacity = 10;
    int size = 0;
    int *items;
    Heap(int c) : items{((int *)malloc(sizeof(int) * c))}, capacity(c) {}
    Heap() : items{((int *)malloc(sizeof(int) * capacity))} {};

private:
    int getLeftChild(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChild(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentIndex(int childIndex) { return (childIndex - 1) / 2; }

    bool hasLeftChild(int parentIndex) { return (2 * parentIndex + 1) < size; }
    bool hasRightChild(int parentIndex) { return (2 * parentIndex + 2) < size; }
    bool hasParentIndex(int childIndex) { return ((childIndex - 1) / 2) >= 0; }

    int getLeftChildItem(int parentIndex) { return 2 * parentIndex + 1; }
    int getRightChildItem(int parentIndex) { return 2 * parentIndex + 2; }
    int getParentItem(int childIndex) { return (childIndex - 1) / 2; }

    void heapifyDown(){
        int index;
        //if it doesn't have any child therefore it's in the bottom of the heap
        while(hasLeftChild(index)){
            int smallerIndex = getLeftChild(index);
            if(hasRightChild(index) && items[smallerIndex] > getRightChildItem(index)){
                smallerIndex = getRightChild(index);
            }
            
            if(items[index] < items[smallerIndex]){
                break;
            }else{
                swap(index , smallerIndex);
                index = smallerIndex;
            }
        }
    }
    
    
    void heapifyUp(){
        int index = size -1;
        while(hasParentIndex(index) && getParentItem(index) > items[index]){
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }


    void swap(int indexOne, int indexTwo)
    {
        int temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }

    void EnsureExtraCapacity()
    {
        if (size == capacity)
        {
            int old = capacity;
            capacity = capacity * 2;
            int *temp = (int *)malloc(sizeof(int) * capacity);
            for(int i = 0 ; i < old; ++i){
                temp[i] = items[i];
            }
            delete(items);
            items = temp;
        }
    }

    public:
    int peak(){
        if(size == 0) throw new out_of_range("There are no items in the heap");
        return items[0];
    }
    int poll(){
        //extract the minimum element and then force the heap to be minified;
        if(size == 0) throw new out_of_range("There are no items in the heap");
        int item = items[0];
        items[0] = items[size -1];
        --size;
        heapifyDown();
        return item;
    }

    void add(int item){
        EnsureExtraCapacity();
        items[size] = item;
        ++size;
        heapifyUp();
    }

};
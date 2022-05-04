#include <bits/stdc++.h>

using namespace std;

class Heap
{
private:
    int capacity = 10;
    int size = 0;
    int *items = new int[10];
    inline int getParentIndex(int u) { return (u - 1) / 2; }
    inline int getLeftChildIndex(int u) { return 2 * u + 1; }
    inline int getRightChildIndex(int u) { return 2 * u; }

    inline int getParent(int u) { return items[getParentIndex(u)]; }
    inline int getLeftChild(int u) { return items[getLeftChildIndex(u)]; }
    inline int getRightChild(int u) { return items[getRightChild(u)]; }

    inline bool hasParent(int u) { return getParent(u) >= 0; }
    inline bool hasLeftChild(int u) { return getLeftChild(u) < size; }
    inline bool hasRightChild(int u) { return getRightChild(u) < size; }

    inline void swap(int i, int j)
    {
        int temp = items[i];
        items[i] = items[j];
        items[j] = temp;
    }

    void amortizeWhenExceed()
    {
        if (size == capacity)
        {
            int copy_items[2 * capacity];
            for (int i = 0; i < capacity; ++i)
                copy_items[i] = items[i];
            delete[] items;
            items = copy_items;
            capacity *= 2;
        }
    }

public:
    int peek()
    {
        if (size == 0)
            throw new out_of_range("there is no elements in the heap");
        return items[0];
    }
    int poll()
    {
        if (size == 0)
            throw new out_of_range("there is no elements in the heap");
        int item = items[0];
        items[0] = items[size - 1];
        --size;
        heapifyDown();
        return item;
    }
    void add(int item)
    {
        amortizeWhenExceed();
        ++size;
        items[size] = item;
        heapifyUp();
    }
    void heapifyUp()
    {
        int index = size - 1;
        while (hasParent(index) && getParent(index) > items[index])
        {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }

    void heapifyDown()
    {
        int index = 0;
        while (hasLeftChild(index))
        {
            int smallerChildIndex = getLeftChild(index);
            if (hasRightChild(index) && getRightChild(index) < getLeftChild(index))
                smallerChildIndex = getRightChildIndex(index);
            if (items[index] < items[smallerChildIndex])
                break;
            swap(index, smallerChildIndex);
            index = smallerChildIndex;
        }
    }
};

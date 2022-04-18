import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    // construct an empty randomized queue
    private int size;
    private int capacity = 1;
    private int front = 0;
    private Item arr[];

    public RandomizedQueue() {
        arr = (Item[]) new Object[capacity];
        size = 0;
    }

    private void amortizeArray() {
        Item[] newArr = (Item[]) new Object[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            newArr[i] = arr[(front + i) % capacity];
        }
        capacity = capacity * 2;
        front = 0;
        arr = newArr;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    // return the number of items on the deque
    public int size() {
        return size;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) throw new IllegalArgumentException();
        if (size >= capacity) {
            amortizeArray();
        }
        arr[(front + size) % capacity] = item;
        ++size;
    }

    // remove and return a random item
    public Item dequeue() {
        if (size == 0) throw new NoSuchElementException();
        int offset = StdRandom.uniform(size);
        int idx = (front + offset) % capacity;
        int lastElementIdx = (front + size - 1) % capacity;
        Item random_item = arr[idx];
        arr[idx] = arr[lastElementIdx];
        arr[lastElementIdx] = null;
        --size;
        return random_item;
    }

    public Item sample() {
        int offset = StdRandom.uniform(size);
        return arr[(front + offset) % capacity];
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new MyIterator();
    }

    private class MyIterator implements Iterator<Item> {
        private Item[] snapShot = (Item[]) new Object[size];
        private int i = 0;

        public MyIterator() {
            for (int i = 0; i < size; ++i) {
                snapShot[i] = arr[(front + i) % capacity];
            }
        }

        @Override
        public boolean hasNext() {
            return size > 0 && arr[(i) % size] != null;
        }

        @Override
        public Item next() {
            if (size > 0 && hasNext()) {
                int offset = StdRandom.uniform(size);
                Item random_item = arr[offset];
                arr[offset] = arr[size - 1];
                arr[size - 1] = null;
                ++i;
                --size;
                return random_item;
            }
            throw new NoSuchElementException();
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        // printing results to standard output
        RandomizedQueue<Integer> rq = new RandomizedQueue<>();
        for (int i = 0; i <= 10; ++i) {
            rq.enqueue(i);
        }
        Iterator<Integer> it = rq.iterator();
        while (it.hasNext()) {
            StdOut.println(it.next());
        }
    }

}

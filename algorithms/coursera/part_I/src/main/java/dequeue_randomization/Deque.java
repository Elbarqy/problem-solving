import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {
    private class Node {
        public Item data;
        public Node next;
        public Node prev;

        Node(Item passedValue) {
            data = passedValue;
        }
    }

    private Node first = null;
    private Node last = null;
    private int size; //4byte

    // construct an empty deque
    public Deque() {
        size = 0;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return size == 0;
    }

    // return the number of items on the deque
    public int size() {
        return size;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        ++size;
        if (first == null) {
            first = new Node(item);
        } else {
            Node currentlyPrev = first;
            Node front = new Node(item);
            currentlyPrev.next = front;
            front.prev = currentlyPrev;
            first = front;
        }
        if (last == null) {
            last = first;
        }
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null)
            throw new IllegalArgumentException();
        ++size;
        if (last == null) {
            last = new Node(item);
        } else {
            Node addedNode = new Node(item);
            last.prev = addedNode;
            addedNode.next = last;
            last = addedNode;
        }
        if (first == null) {
            first = last;
        }
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (size <= 0) {
            throw new NoSuchElementException();
        }
        --size;
        if (first != null) {
            Item data = first.data;
            first = first.prev;
            return data;
        }
        Item data = last.data;
        last = null;
        return data;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (size <= 0) {
            throw new NoSuchElementException();
        }
        --size;
        if (last != null) {
            Item data = last.data;
            last = last.next;
            return data;
        }
        Item data = first.data;
        first = null;
        return data;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {

        return new Iterator<Item>() {
            private Node current = first;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public Item next() {
                if (hasNext()) {
                    Item data = current.data;
                    current = current.prev;
                    return data;
                }
                throw new NoSuchElementException();
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException();
            }
        };
    }


    public static void main(String[] args) {
        // printing results to standard output
//        Deque<Integer> deque = new Deque<Integer>();
//        for (int i = 0; i < 1000; i++) {
//            if (StdRandom.bernoulli(0.4)) {
//                deque.addFirst(i);
//            } else {
//                deque.addLast(i);
//            }
//        }
//
//
//        while (!deque.isEmpty()) {
//            if (StdRandom.bernoulli(0.3)) {
//                StdOut.println(deque.removeLast());
//            } else {
//                StdOut.println(deque.removeFirst());
//            }
//        }
        Deque<Integer> deque = new Deque<>();
        for (int j = 1; j <= 10; j++)
            deque.addFirst(j);
        Iterator<Integer> iterator = deque.iterator();
        while (iterator.hasNext()) {
            StdOut.println(iterator.next());
        }
    }
}
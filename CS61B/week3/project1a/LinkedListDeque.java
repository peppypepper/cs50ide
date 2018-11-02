
//should accept any generic type. Pay attention to rules of thumbs on the last slide, lecture 5
//use circular sentinel instead of double sentinel.
//each node should have 2 pointers
public class LinkedListDeque<TypeType> {
    //a node class with 2 pointers
    private class Node {
        public TypeType item;
        public Node next;
        public Node prev;

        //node constructor
        public Node(TypeType item, Node next, Node prev) {
            this.item = item;
            this.next = next;
            this.prev = prev;
        }
    }

    public int size;

    private Node first;


    //LLD constructor
    public LinkedListDeque() {
        size = 1;

    }

    //adds an item of type T to the front of the deque
    public void addFirst(T item) {

    }

    //adds an item of type T to the back of the deque
    public void addLast(T item) {

    }

    //returns true if deque is empty, false otherwise
    public boolean isEmpty() {

    }

    //return number of items in the deque
    public int size() {

    }

    //prints the items in the deque from first to last, separated by a space
    public void printDeque() {

    }

    //removes and returns the item at the front of the deque
    //if no such item exists, returns null
    public T removeFirst() {

    }

    //removes and returns the item at the back of the deque
    //if no such item exists, returns null
    public T removeLast() {

    }

    //gets the item at the given index.
    //if no such item exists, returns null. Must not alter the deque
    public T get(int index) {

    }

    //same as get, but uses recursion
    public T getRecursive(int index) {

    }

}



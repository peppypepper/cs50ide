
//should accept any generic type. Pay attention to rules of thumbs on the last slide, lecture 5
//use circular sentinel instead of double sentinel.
//each node should have 2 pointers
public class LinkedListDeque<Generic> {
    //a node class with 2 pointers
    private class Node {
        //instance variables
        public Generic item;
        public Node next;
        public Node prev;

        //node constructor
        public Node(Generic item, Node next, Node prev) {
            this.item = item;
            this.next = next;
            this.prev = prev;
        }
    }

    private int size;

    private Node sentinel;


    //constructor with 0 item
    public LinkedListDeque() {
        sentinel = new Node(null, sentinel.next, sentinel.prev);
        size = 0;
    }

    //adds an item of type generic to the front of the deque
    public void addFirst(Generic item) {
        size++;
        Node newNode = new Node(item, sentinel.next, sentinel);
        sentinel.next = newNode;
        sentinel.next.prev = newNode;

    }

    //adds an item of type generic to the back of the deque
    public void addLast(Generic item) {
        size++;
        Node newNode =  new Node(item, sentinel, sentinel.prev);
        sentinel.prev = newNode;
        sentinel.prev.next = newNode;
    }

    //returns true if deque is empty, false otherwise
    public boolean isEmpty() {
        if (size < 1) {
            return true;
        }
        return false;
    }

    //return number of items in the deque
    public int size() {
        return size;
    }

    //prints the items in the deque from first to last, separated by a space
    public void printDeque() {
        Node k = sentinel.next;
        while (k != sentinel) {
            System.out.print(k.item + " ");
            k = k.next;
        }
        System.out.println();
    }

    //removes and returns the item at the front of the deque
    //if no such item exists, returns null
    public Generic removeFirst() {
        if (size < 1) {
            return null;
        } else {
            Generic firstItem = sentinel.next.item;
            sentinel.next = sentinel.next.next;
            sentinel.next.next = sentinel;
            size--;
            return firstItem;
        }
    }

    //removes and returns the item at the back of the deque
    //if no such item exists, returns null
    public Generic removeLast() {
        if (size < 1) {
            return null;
        } else {
            Generic lastItem = sentinel.prev.item;
            sentinel.prev.next = sentinel;
            sentinel.prev = sentinel.prev.prev;
            size--;
            return lastItem;
        }
    }

    //gets the item at the given index.
    //if no such item exists, returns null. Must not alter the deque
    public Generic get(int index) {
        if (size < 1 || index >= size) {
            return null;
        } else if (index == 0) {
            return sentinel.next.item;
        } else if (index == size - 1) {
            return sentinel.prev.item;
        } else {
            Node k = sentinel.next;
            for (int i = 0; i < index; i++) {
                k = k.next;
            }
            return k.item;
        }
    }

    //same as get, but uses recursion
    public Generic getRecursive(int index) {
        if (index == 0) {
            return sentinel.next.item;
        }

            Node p = sentinel.next;
            return getHelper(index, p);
    }

    private Generic getHelper(int index, Node p) {
        if (index == 0) {
            return p.item;
        } else {
            p = p.next;
            return getHelper(index - 1, p);
        }
    }


    public static void main(String[] args) {
        LinkedListDeque<String> L = new LinkedListDeque<String>();
        L.addFirst("pepper");
        L.addFirst("salt");
        L.addFirst("sugar");
        L.addFirst("cinnamon");
        L.addFirst("nutmeg");
        System.out.println(L.get(0));
        System.out.println(L.get(1));
        System.out.println(L.get(2));
        System.out.println(L.get(3));
        System.out.println(L.get(4));
        System.out.println(L.get(5));
        //L.addLast("paprika");
        //L.removeFirst();
        //L.removeLast();
        System.out.println("list is empty: " + L.isEmpty());
        System.out.println("list size = " + L.size());
        System.out.println("first item = " + L.sentinel.next.item);
        System.out.println("last item = " + L.sentinel.prev.item);
        L.printDeque();
    }

}



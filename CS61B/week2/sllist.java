public class sllist {
    private class IntNode {
        public int item;
        public IntNode next;
        //node constructor
        public IntNode(int item, IntNode next) {
            this.item = item;
            this.next = next;
        }
    }

    //an instance variable, type IntNode, name first
    private IntNode first;
    private int size;

    //constructor
    public sllist(int x) {
        first = new IntNode(x, null);
        size = 1;
    }

    //constructor of an empty list
    public sllist() {
        first = null;
        size = 0;
    }

    //method
    public void addFirst(int x) {
        first = new IntNode(x, first);
        size++;
    }
    //method
    public int getFirst() {
        return first.item;
    }

    //method
    public void addLast(int x) {
        //a fix for the addLast() to an empty list bug
        //works but not pretty, this is where the sentinel comes in
        if (first == null) {
            first = new IntNode(x, null);
            return;
        }

        IntNode p = first;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new IntNode(x, null);
        size++;
    }

    //method
    public int getLast() {
        IntNode p = first;
        while (p.next != null) {
            p = p.next;
        }
        return p.item;
    }


    //method
    //better to add a size variable to first and update size
    private static int size(IntNode p) {
        if(p.next == null) {
            return 1;
        }
        return 1 + size(p.next);
    }

    public int size(){
        return size(first);
    }

    public static void main(String[] args) {
        sllist L = new sllist();
        L.addLast(-4);
        L.addFirst(10);
        L.addFirst(5);
        L.addLast(0);
        System.out.println("list size = " + L.size());
        System.out.println("first item = " + L.getFirst());
        System.out.println("last item = " + L.getLast());
    }


}
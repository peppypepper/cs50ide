public class sllistSentinel {
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
    //replace first with sentinel, sentinel carries a random value and always present
    //the first item, if exists, is at sentinel.next
    private IntNode sentinel;
    private int size;

    //constructor, 1 item list
    public sllistSentinel(int x) {
        sentinel = new IntNode(15, null);
        sentinel.next = new IntNode(x, null);
        size = 1;
    }

    //constructor of an empty list
    public sllistSentinel() {
        sentinel = new IntNode(15, null);
        size = 0;
    }

    //method
    public void addFirst(int x) {
        //whoever used to be in front of the line, now second in line
        sentinel.next = new IntNode(x, sentinel.next);
        size++;
    }
    //method
    public int getFirst() {
        return sentinel.next.item;
    }

    //method
    public void addLast(int x) {
        //start at the sentinels
        IntNode p = sentinel;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new IntNode(x, null);
        size++;
    }

    //method
    public int getLast() {
        IntNode p = sentinel;
        while (p.next != null) {
            p = p.next;
        }
        return p.item;
    }


    //method
    //better to add a size variable to first and update size

    public int size(){
        return size;
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
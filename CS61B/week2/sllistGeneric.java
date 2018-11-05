public class sllistGeneric<Generic> {
    private class IntNode {
        public Generic item;
        public IntNode next;
        //node constructor
        public IntNode(Generic item, IntNode next) {
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
    public sllistGeneric(Generic x) {
        sentinel = new IntNode(null, null);
        sentinel.next = new IntNode(x, null);
        size = 1;
    }

    //constructor of an empty list
    public sllistGeneric() {
        sentinel = new IntNode(null, null);
        size = 0;
    }

    //method
    public void addFirst(Generic x) {
        //whoever used to be in front of the line, now second in line
        sentinel.next = new IntNode(x, sentinel.next);
        size++;
    }
    //method
    public Generic getFirst() {
        return sentinel.next.item;
    }

    //method
    public void addLast(Generic x) {
        //start at the sentinels
        IntNode p = sentinel;
        while (p.next != null) {
            p = p.next;
        }
        p.next = new IntNode(x, null);
        size++;
    }

    //method
    public Generic getLast() {
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
        sllistGeneric<String> L = new sllistGeneric<String>("pepper");
        L.addFirst("khoa");
        L.addFirst("thao");
        L.addLast("brownie");
        System.out.println("list size = " + L.size());
        System.out.println("first item = " + L.getFirst());
        System.out.println("last item = " + L.getLast());
    }


}
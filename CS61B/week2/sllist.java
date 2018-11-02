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
    //constructor
    public sllist(int x) {
        first = new IntNode(x, null);
    }
    //method
    public void addFirst(int x) {
        first = new IntNode(x, first);
    }
    //method
    public int getFirst() {
        return first.item;
    }


}
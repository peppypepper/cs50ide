//a less "naked" data structure, abstract/hide away some of that pointer syntax
//singly linked list
//SLList class acts as a middle man between user and the "naked" recursive data structure.
//Allows us to store meta data about the entire list. e.g size, min, max,...
//Intlist can do these things too, but SLList is a much more natural way
//this is OOP, we let the object controls everything, controls other objects, methods, data,..
//java allows us to defer type selection until declaration <typeHolder>
public class SLList<typeHolder> {

    //a nested class
    //private because no other class but SLList would use typeNode
    //static cause no instance gonna use its method and save some memory
    private class typeNode {
        public typeHolder item;
        public typeNode next;

        //node constructor
        public typeNode(typeHolder i, typeNode n) {
            item = i;
            next = n;
        }

    }

    //because messing with the first property of SSList object might have unforseen consequences.
    //we're going to make this variable private. So when someone try to excess typeNode.item or next,
    //they won't be able to. Code won't compile.
    //private keyword is another way to hide away things/concepts that you don't wanna your user have
    //to worry about. Only you, who have access to the source code can mess with it.
    //this is called access control
    //private keyword soft signals to other programmers that they shouldn't mess with it
    //public keyword methods are expected to be there at all times. Like a car steering wheel.
    private typeNode first;

    //add a size variable to each node to keep track of the list size
    private int size;

    //constructor, this SLList object, takes another object, typeNode, as its component
    //first is a wrapper for typeNode in sense. It abstract away the pointer so the user don't have to
    //deal with it or care for it. Look at the drawing.
    public SLList(typeHolder x) {
        //make the sentinel node
        sentinel = new typeNode(15, null);
        //it points to the first item in this SLList
        sentinel.next = new typeNode(x, null);
        //since we're employing the sentinel node, we no longer need to the first node
        //first = new typeNode(x, null);
        size = 1;
    }

    //gonna be a special head typeNode, will always be there
    private typeNode sentinel;
    //another constructor, this one creates an empty SLList, with a sentinel
    //the first item (if exists) is at sentinel.next
    public SLList() {
        //15 is just an arbitrary number
        sentinel = new typeNode(15, null);
        size = 0;
    }


    //a method to add x to the front of the list, L.addFirst(2)
    public void addFirst(typeHolder x) {
        //add a new typeNode to the front of the list, typeNode takes an int x,
        //first = new typeNode(x, first);
        //no longer need first, we're using sentinel now, welcome to the evolution
        sentinel.next = new typeNode(x, sentinel.next);
        //update list size
        size++;
    }
    //a method to return the first element of the list, L.getFirst()
    public typeHolder getFirst() {
        return sentinel.next.item;
    }

    //a method to L.addLast(4), go to the back, make a new node, put x in
    public void addLast(typeHolder x) {
        //create an arbitrary typeNode with no value, name it p, set it to the first position
        //typeNode p =  first;
        //we use the sentinel now
        typeNode p = sentinel;
        //traverse it to end of list
        while (p.next != null) {
            p = p.next;
        }
        //when at the end of the list, add a new node and put x in it.
        p.next = new typeNode(x, null);
        //update list size
        size++;
    }


    //simply call the private size() method publicly for user's ease of use.
    public int size() {
        return size(first);
    }

    //we added a size variable to each node and update it everytime we add or subtract a node from the list
    //we now have size information at all time. Without need to travserse through a list of millions of items
    //this takes a little more memory but spread out the work and is a more "efficient" size() method
    public int fastSize() {
        return size;
    }

}




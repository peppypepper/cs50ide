//in java, lists are dynamic, arrays are static


//here is a simple integer list,  a "naked" recursive data structure
//"naked" because the user has to interact with pointers and manually manipulate things
public class IntList {
    //first box stores value, declare instance variable
    public int first;
    //rest box stores reference, declare instance variable
    public IntList rest;
    //first and rest go together as unit, which form an element. These elements chain together to make the list

    public static void main(String[] args) {

        //declare, instantiation and assignment of a new int list
        IntList L = new IntList();

        //lack of a constructor, manually add data to each variable
        //put 5 in the first box
        L.first = 5;
        //set reference to null, because it's not pointing to anyting right now
        L.rest = null;

        //this process makes a lot more sense when drawn out.
        //create a new list element. Start with setting the current pointer to point to the new first box
        L.rest = new IntList();
        //put a value in the new first box
        L.rest.first = 10;
        //at this point, the rest pointer of the second is undefined. It's just sitting there, empty

        //repeat the process to create another list element
        //here we assign the second rest pointer to point to the third first box
        L.rest.rest = new IntList();
        L.rest.rest.first = 15;

        //there has to be a better way to build lists. There is.

        //a constructor, put a number in the first box, put an IntList object in the rest box
        public IntList(int f, IntList r) {
            first = f;
            rest = r;
        }
        //start an IntList using the constructor
        IntList L = new IntList(15, null);
        //add a new element using the constructor, passing L into r, so r can point the previous element
        L = new Intlist(10, L);
        //repeat
        L = new Intlist(5, L);
        //the interesting thing here is, the new elements are added to the front of the list.
        //new head everytime. This list goes 5->10->15. The null pointer is at the end.


        //we need a size method to tell us how big the list is. Similar to array.length() but L.size()
        //use recursion
        public int size() {
            //base case
            if (rest == null) {
                return 1;
            } else {
                return 1 + this.rest.size();
            }
        }

        //size method without recursion
        public int iterativeSize() {
            IntList p = this;
            int size = 0;
            while (p != null) {
                //move to the next node, check if pointer is null, if not, not the end yet, repeat
                p = p.rest;
                size++;
            }
            return size;
        }

        //a method to return the ith item of the intList, similar to array[i], L.get(0) = 5
        //front of list is 0th item
        public int get(int i) {
            //base case is when i = 0, first item, just return first
            if (i == 0) {
                return first;
            } else {
                //get the next one
                //in a sense we're traversing the list, but instead of a loop, we use recursion
                return rest.get(i - 1);
            }

        }
        //a method that returns an IntList identical to L, but with all values incremented by x
        //values in L cannot change. Make a new list
        public static IntList incrList(IntList L, int x) {
            //every new node, is an L node + x
            if(L.rest != null) {
                return new IntList(L.first + x, L);
            }
            return new IntList(L.first + x, null);

            IntList M = new IntList();



        }

        //return an IntList identical to L, but all values incremented by x
        //no new list here, just a new pointer that changes L.
        public static IntList dincrList(IntList L, int x) {

        }


    }
}
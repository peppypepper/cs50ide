//create our own data structures, collections, singly-linked lists, much more flexible and dynamic than arrays
// there is no indexing with linked lists, you need to search everytime

/* a linked list node is a special kind of struct with two members:
    data of some data type (int, char, float,...)
    a pointer to another node of the same type
a set of nodes together can be thougt of as forming a chain of elements that we can follow from beginning to end. */

typedef struct sllist // structure declaration using typedef to rename
{
    VALUE val;  // some value
    struct sllist* next; // a pointer that point to another node of the same type, have to reuse struct sllist because sllnode does not yet exist at this line
}
sllnode; // call this new structure sllnode, this is the permanent name



//create a new node once you have declared it
sllnode* create(Value val); // malloc space, check space, create a linked list
sllnode* new = create(6);

// finding
bool find(sllnode* head, VALUE val); // this is how we find the linked list, just need to first element, make it global
bool exists = find(list,6); // list is the name of the first element pointer, we're looking for number 6 in this linked list. There is a traversal pointer that already exists with every node
// that contains the location of the next node. The value of the last node traversal pointer is NULL, it points to nothing.

//inserting
sllnode* insert(sllnode* head, VALUE val); // inserting a new node, malloc space, check that space, need to the node head and the value we want to insert at the beginning of the list, return a pointer to the new head.
// less procesing time and power when inserting at the beginning versus the end

list = insert(list,12); // connect new element before moving the head or you risk losing the list because you'd have no way to reference the rest of the list


//delete the entire linked list
void destroy(sllnode* head); // if reached a null pointer, stop. Delete the rest of the list, then free the current node, this is recursion. You delete from the end/null ponter and work backward according to the call stack
// delete frame by frame. See recursion.c

//delete a single node from a singly linked list is difficult. look at doubly linked list


void free_pointer(pointer)
{
    if pointer == NULL
    {
        free(pointer)
    }
    else:
    {
        free_pointer(pointer);
    }
}







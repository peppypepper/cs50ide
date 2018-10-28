// stacks data structure, not the memory stack
// can be used as an array or a linked list
// if you need data is added on top and remove from the top. LIFO: last in, first out structure.
// push: add a new element to the top, accpet a pointer,
// pop: remove the top most element

// array based implementation
typedef struct _stack
{
    VALUE array[CAPACITY];
    int top; //store what is on top at the moment
}
stack;

stack s; //declare stack s, this will allocate some memory for us according to the capcaity
s.top = 0; //assign the current position of the top of the stack, not a value
push(&s, 28); // push the value 28 to the top of the stack and update the top position of the stack
int x = pop(&s); // assign the last element we assign to the stack to variable x. That last element is not deleted from the stack, but since pop will update the top position, it will get override next time we add something

// linked list based implementation
typedef stuct _stack
{
    VALUE val;
    struct _stack next*;
}
stack;

// always maintain a pointer to the head of the linked list. make it a global variable
// to push, dynamically allocate a new node, set its next pointer to point to the current head, then move the head pointer to the new node
trav = trav next
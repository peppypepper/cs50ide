// how pointers and dynamically allocated memory works using malloc() and free()

int m; //creat a box that can hold an integer, that box is called m, lives on the stack
int* a; // creat a box that can hold a pointer-type-int, that box is called a, lives on the stack
int* b = malloc(sizeof(int)); // creat 2 boxes. A b box (pointer), that contains the address of a second box that is nameless and empty at the momment. b reference this empty box
a = &m; // box a now get the memory address of box m. a points to m
a = b; // box a now hold the memory address of the empty box that was created on line 5
m = 10; // put number 10 in the m box
*b = m + 2; // right to left. 10 + 2 = 12. Assisgn 12 to the empty box that was created on line 5 by dereferencing pointer b or pb. That box is still nameless but now has a number 12 in it.
free(b); // no longer need that empty box with 12 in it. Return it back to memory. That box disappears. Now pa and pk points to nothing/ NULL
*a = 11; // assign 11 to the location where pa is pointing to by dereferencing pointer a, but pa is pointing to nothing, that box disappear when we free(b), this is a segmentation fault. program crash
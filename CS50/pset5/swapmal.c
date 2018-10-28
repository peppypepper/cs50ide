int main(void)
{
    int *x; //declare 2 empty integer pointers. 2 address boxes but no addresses.
    int *y;

    x = malloc(sizeof(int)); // declare a chunk memory in the heap and store its address in x.
    *x  = 42; // go to that address store in x and put 42 there. Remember, 42 is not stored in x. 42 is stored at some memory address that x has.
    *y = 13; // got that address a put a 13 there. but seg fault because there is no address to follow. Computer crashes.
    y = x; // this line says copy the address in x and put it in y. Make a copy of the map, not going to that location.
    *y = 13; // put 13 in the address location that y contains, essentially update 42 to 13
}

// stack overflow, heap overflow, buffer overflow
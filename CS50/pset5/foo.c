#include <string.h>

void foo(char *bar) //buffer overflow exploit. cs50help  and valgrind detect memory leaks
{
    char c[12]; //create an array size 12
    memcpy(c, bar, strlen(bar));
}

int main(int argc, char *argv[])
{
    foo(argv[1]); // call a function
}


#include <stdio.h>

int main(void)
{
    int x;
    printf("x: ");
    scanf("%i", &x); //scanf read from keyboard. & get me the address of something. * go to the address of something. & and * kinda undo each other.
    printf("x: %i\n", x);
}
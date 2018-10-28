#include <stdio.h>
#include <cs50.h>


//prototype allows us to keep the main function up top, while introducing the new feature to the compiler
int square(int n);

int main(void)
{
    int x = get_int("x: ");
    printf("x^2 = %i\n", square(x));
}

//squaring
int square(int n)
{
    return n * n;
}



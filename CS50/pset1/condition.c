#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for x
    int x = get_int("x: ");

    //prompt user for y
    int y = get_int("y: ");

    // compare x and y
    if(x < y)
    {
        printf("x is smaller than y\n");
    }
    else if(x > y)
    {
        printf("x is bigger than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}
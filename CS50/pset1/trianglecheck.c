#include <stdio.h>
#include <cs50.h>


int main(void)
{
    float a = get_float("a: ");
    float b = get_float("b: ");
    float c = get_float("c: ");

    if (a > 0 && b > 0 && c > 0)
    {
        if (a + b > c && a + c > b && b + c > a)
        {
            printf("it's a triangle\n");
        }
        else
        {
            printf("not a triangle\n");
        }
    }
    else
    {
        printf("not a triangle\n");
    }
}
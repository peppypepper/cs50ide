// write a program that return fizz at multiple of 3, buzz at multiple of 5, fizzbuzz at both, to 100

#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int n = 1;
    for (int i = 0; i < 101; i++)
    {
        if(n % 3 == 0 && n % 5 == 0)
        {
            printf("fizzbuzz\n");
        }
        else if (n % 5 == 0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%i\n", n);
        }
        printf("\n");
        n++;

    }
}
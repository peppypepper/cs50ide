
#include <stdio.h>
#include <cs50.h>


int fact(int n); /* when main is called to perform fact(5), 8 function frames stack on top of each other to perform this task. Only one function frame is active at one time. From the bottom up: main(), get_int(), printf(),
              fact(5), fact(4), fact(3), fact(2), fact(1). When we get to fact(1) frame, it calculates, return its value then get pop off the stack. Then Fact(2) become active and so on. Printf prints out 120, it pops off then
              main pop off, program exit. */

int main(void)
{
    int n = get_int("x: ");
    printf("%i\n", fact(n));
}

int fact(int n)
{
    if(n == 1)
        return 1;
    else
        return n * fact(n-1);
}
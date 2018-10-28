#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void) // can't compare strings. Strings in C are actually char *, pointers
{
    string s = get_string("s: ");
    /*computer only save the address/pointer of the first character array in memory.
    It depends on the null \0 in memory to know when the string ends. So s === t, is only compare the first elements. */

    char *t = get_string("t: "); // string t is actually char *t that cs50 built to make it user friendly

    if (strcmp(s,t) == 0) //stringcompare function, s and t are visually compare. Gives 0,1,-1. The strcmp function actually compare the characters by going to the memory addresses.
    {
        printf("same\n");
    }
    else
    {
        printf("different\n");
    }
}
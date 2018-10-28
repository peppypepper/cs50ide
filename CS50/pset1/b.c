#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("input: ");
    printf("output: ");
    for (int i= 0; i < strlen(s); i++)
    {
        printf("%c %i \n", s[i], (int) s[i]); //printing each letter with typecasting  to number
    }
}
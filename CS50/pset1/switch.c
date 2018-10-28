#include <stdio.h>
#include <cs50.h>

char c = get_char("are you sure? ");

int main(void)
{
    switch(c)
    {
        case 'Y':
        case 'y':
            printf("yes\n");
            break;
        case 'N':
        case 'n':
            printf("no\n");
            break;
    }
}
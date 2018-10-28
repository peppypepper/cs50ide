#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) // void signals main takes no input. int main(int argc, string argv[])
{
    string s = get_string("before: ");
    printf("after: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - ('a' - 'A'));  //can also use islower, isupper, toupper, look at reference page for more info. There is a \0 in the memory to represent the end of the string.
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}

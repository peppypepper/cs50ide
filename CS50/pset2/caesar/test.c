#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    string key = "ABC";
    int keyLength = strlen(key);


    for (int i = 0; i < keyLength; i++)
    {
        key[i] = tolower(key[i]);
        key[i] = key[i] - 97;
    }

    printf("%s", key);
}

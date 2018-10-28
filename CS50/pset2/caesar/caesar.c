//didn't do

#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])

{
//this make prints an error if argc is not 2
    if (argc != 2)
    {
        printf("Need exactly 2 command line arguments\n");
        return 0;
    }
//this converts key char to key int
    int key = atoi(argv[1]);

//this makes sure it's a non-negative integer
    if (key <= 0 )
    {
        printf("Key needs to a positive number\n");
        return 0;
    }
    else
    {
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
//check lowercase
            if (islower(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 97 + key) % 26) + 97));
            }
//check uppercase
            else if (isupper(plaintext[i]))
            {
                printf("%c", (((plaintext[i] - 65 + key) % 26) + 65));
            }
            else
            {
                printf("%c", plaintext [i]);
            }

        }
    printf("\n");
    return 0;
    }
}

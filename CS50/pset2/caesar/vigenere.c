#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    //get 2 command line arguments
    if (argc != 2)
    {
        printf("need 2 command line arguments\n");
        return 0;
    }

    // check key to see if all alphabetical
    string key = argv[1];
    int keyLength = strlen(key);
    for (int i = 0; i < keyLength; i++)
    {
        if (isalpha(key[i]))
        {
            continue;
        }
        else
        {
            printf("key needs to be all alphabetical\n");
            return 0;
        }
    }

    //lowercase key and get alphabetical index
    for (int i = 0; i < keyLength; i++)
    {
        key[i] = tolower(key[i]);
        key[i] = key[i] - 97;
    }

    printf("%s", key);


    // get plaintext
    string plaintext = get_string("plaintext:  ");

    // gett ciphertext
    printf("ciphertext: ");

    for (int i = 0, j = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            //check upper
            if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 65 + key[j]) % 26) + 65);
                j++;
                j =  j % keyLength;
            }
            else  //check lower
            {
                printf("%c", ((plaintext[i] - 97 + key[j]) % 26) + 97);
                j++;
                j = j % keyLength;
            }
        }
        else // print spaces and symbols
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}











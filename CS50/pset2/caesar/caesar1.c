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



    // convert key string to key int
    int key = atoi(argv[1]);

    // get plaintext
    string plaintext = get_string("plaintext:  ");

    // gett ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            //check upper
            if (isupper(plaintext[i]))
            {
                printf("%c", ((plaintext[i] - 65 + key) % 26) + 65);
            }
            else  //check lower
            {
                printf("%c", ((plaintext[i] - 97 + key) % 26) + 97);
            }
        }
        else // print spaces and symbols
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

}














#include <stdio.h>
#include <cs50.h>


int main(void)
{
    //prompt user for pyramid height
    int height;
    do
    {
        height = get_int("Please enter height between 1 to 23: ");
    }
    while(height < 0 || height > 23);

    //new lines
    for (int i = 0; i < height; i++)
    {
        //print spaces
        for (int s = height; s > i; s--)
        {
            printf(" ");
        }

        //print left hashes
        for (int j = 0; j < i+2; j++ )
        {
            printf("#");
        }

        //print gap
        printf("  ");

        //print right hashes
        for (int j = 0; j < i+2; j++ )
        {
            printf("#");
        }

        //new line
        printf("\n");


    }
}
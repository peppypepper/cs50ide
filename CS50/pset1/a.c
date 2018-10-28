#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //prompt user for the height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height < 0 || height > 23);

    // print this many rows
    for (int i = 0; i < height; i++)
    {
        // print this many columns
        for (int j = 0; j < height; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
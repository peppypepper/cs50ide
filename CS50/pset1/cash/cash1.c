#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //ask for change
    float change;
    do
    {
        change = get_float("change owed in decimal please: ");
    }
    while(change < 0);

    // convert change to penny
    float penny = floor(change * 100);


    // start coins count
    int coins = 0;

    //use modulo and divison
    int leftOver = penny /= 25




    printf("%i\n", coins);

}

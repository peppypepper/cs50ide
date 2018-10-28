#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for change
    float change;
    do
    {
        change = get_float("change owed in decimal please: ");
    }
    while(change < 0);

    float penny = change * 100;
    int coins = 0;

    while (penny >= 25)
    {
        penny -= 25;
        coins++;
    }

    while (penny >= 10)
    {
        penny -= 10;
        coins++;
    }

    while (penny >= 5)
    {
        penny -= 5;
        coins++;
    }

    while (penny >= 1)
    {
        penny -= 1;
        coins++;
    }

    printf("%i\n", coins);

}

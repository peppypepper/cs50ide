#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string("Name: "); //get user name
    char initials[4]; // make an empty array of length 4
    int counter = 0; // count initial array position because name array is much longer than initial array
    for (int i = 0; i < strlen(name); i++) // loop through name array using its length
    {
        if(isupper(name[i])) // when find an upper character
        {
            initials[counter] = name[i]; // from right to left, assign that character to the initial array at the counter position, first one is [0] as on line 10
            counter++; // tick counter and loop continue until it encounters the next capital character
        }
    }

    initials[counter] = '\0'; //assign the null value to the end of initial array signalling end of string, not sure if necessary
    printf("Initials: %s\n", initials); //print initial array
}
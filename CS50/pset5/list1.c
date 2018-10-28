// implements a list of unique numbers using an array of fixed length
//1:05 video
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //memory for numbers
    int *numbers = NULL; //number pointer, no address
    int capacity = 0;

    //prompt for numbers (until EOF)
    int size = 0;
    while (true) //infinitely check for number
    {
        //prompt for number
        int number = get_int("number: ");

        //check for EOF
        if (number == INT_MAX) //a feature from get_int
        {
            break;
        }
    }


    //prompt for numbers
    int size = 0; // initialized size and give it a value of 0
    while (size < capacity)
    {
        //prompt for number
        int number = get_int("number: ");

        //check whether number is already in list
        bool found = false;
        for (int i =0; i < size, i++)
        {
            if(numbers[i] == number)
            {
                found = true;
                break;
            }
        }

        //if number not found in list, add to list
        if(!found)
        {
            numbers[size] = number;
            size++;
        }
    }

    //print numbers
    for(int i = 0; i <size; i++)
    {
        printf("%i\n", numbers[i]);
    }


}



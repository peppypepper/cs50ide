// implements a list of unique numbers using an array of fixed length

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask user for capacity
    int capacity; //initialize capacity
    do
    {
        capacity = get_int("capacity: ");
    }
    while (capacity <1);

    //memory for numbers
    int numbers[capacity]; //make an empty array size capacity and name it numbers

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



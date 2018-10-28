#include <stdio.h>
#include <cs50.h>

int sumOfOddPlaces(long number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number/100;
    }
    return sum;
}


int sumOfEvenPlaces(long number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += sumOfEachPlaces % 100;
        number/100;
    }
    return sum;
}

int sumOfEachPlaces(int number)
{
    int sum = 0;
    for(int i = 0, i < 2, i++)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}



















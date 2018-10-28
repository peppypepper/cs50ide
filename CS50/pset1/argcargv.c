#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) //argument vector/array, string-type in this case, first element argv[0], last element argv[argc -1], argument count will store the number of command-line argumentsthe user typed when the program was executed.
{
    if(argc ==2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello world\n");
    }
}
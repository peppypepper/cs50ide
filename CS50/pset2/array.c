#include <stdio.h>
#include <cs50.h>


int main(void)
{

    //type name[size];

    int student_grades[40];
    double menu_prices[8];

    //declare an array type boolean, name truthtable, size 10 (index 0-9), empty
    //bool truthtable[10];
    //assignment
    //truthtable[2] = false;
    //segmentation fault
    //truthtable[10] = false;

    //instantiation syntax, set up an array type boolean, name truthtable, size 3 and assign values to the array
    //bool truthtable[3] = {false, true, true};

    //a "2 dimensional" array, 10x10 grid
    bool battleship[10][10];

    //fill an array size 100
    int index[100];
    for (int i = 0; i<100; i++)
    {
        index[i] = i;
        //printf("%i\n", index[i]);
    }
    //copy one array to another
    int foo[5] = {1,2,3,4,5};
    int bar[5];
    for(int i = 0; i < 5; i++)
    {
        bar[i] = foo[i];
        printf("%i\n", bar[i]);
    }

}
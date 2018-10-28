//integer arithmetic

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt user for x
    float x = get_float("x: ");

    // prompt user for y
    float y = get_float("y: ");

    // perform arithmetic
    printf("%f plus %f is %f\n", x, y, x + y);
    printf("%f divided by %f is %f\n", x, y, x / y);

}
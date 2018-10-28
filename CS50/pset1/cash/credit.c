//not my solution
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cardNumber;

    // prompt the user until they enter positive number
    do
    {
        cardNumber= get_long_long("Number: ");
    }
    while (cardNumber <= 0);

    int currentDigit;
    int firstDigit;
    int secondDigit;
    int cycleCounter = 1;
    int oddSum = 0;
    int evenSum = 0;
    int product;
    int totalSum;

    // iterate over a card number to get first two digits and sums needed for a card validity check
    while (cardNumber > 0)
    {
        currentDigit = cardNumber % 10;

        // get first two digits
        if (cardNumber < 100)
        {
            if (cardNumber < 10)
            {
                firstDigit = currentDigit;
            }
            else
            {
                secondDigit = currentDigit;
            }
        }

        // get oddSum and evenSum
        if (cycleCounter % 2 == 0) // blue/even numbers
        {
            product = currentDigit * 2;
            // if the product consists of two digits, split it and add the digits individualy
            if (product >= 10)
            {
                int productDigit;
                for (int i = 0; i < 2; i++)
                {
                    productDigit = product % 10;
                    evenSum += productDigit;
                    product /= 10;
                }
            }
            else
            {
                evenSum += product;
            }
        }
        else //orange/odd numbers
        {
            oddSum += currentDigit;
        }
        // remove one digit from the right
        cardNumber /= 10;
        cycleCounter++;
    }

    // checksum
    totalSum = oddSum + evenSum;
    if (totalSum % 10 != 0)
    {
        printf("INVALID\n");
    }
    // card issuer check
    else
    {
        int numberOfDigits = cycleCounter - 1;
        int firstTwoDigits = firstDigit * 10 + secondDigit;

        if (numberOfDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (numberOfDigits == 16 && (firstTwoDigits > 50 && firstTwoDigits < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((numberOfDigits == 13 || numberOfDigits == 16) && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
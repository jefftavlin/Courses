#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Get's the best amount of change for user
int main(void)
{
    long number = 0;
    while (true)
    {
        // Get the change from the user
        number = get_long("Number: ");

        if (number > 0)
        {
            break;
        }
    }

    long count = 0;
    long n = number;
    while (n != 0)
    {
        n /= 10;
        ++count;
    }

    long power = pow(10, count - 1);
    long first_number = (number / power) % 10;
    long second_number = (number / (power / 10)) % 10;

    int sum;
    long result, base = 0;
    int check = 0;
    long i;

    // For loop to calc the sumcheck logic
    for (i = 0; i < count; i++)
    {
        base = pow(10, i);
        if (i % 2 != 0)
        {
            result = (number / base) % 10;
            if (result * 2 > 10)
            {
                result = (2 * result % 10) + 1;
                sum  = sum + result;
            }
            else if (result * 2 < 10)
            {
                result = 2 * result;
                sum = sum + result;
            }
            else if (result * 2 == 10)
            {
                result = 1;
                sum = sum + result;
            }
        }
        else
        {
            result = (number / base) % 10;
            sum = sum + result;
        }
    }
    sum = sum % 10;

    // Checks to see which type of card is presented based on sum, count, first, second
    if (count > 16)
    {
        printf("INVALID\n");
    }
    else if (count == 13 || count == 16)
    {
        if (first_number == 4)
        {
            if (sum == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else if (first_number == 5)
        {
            if (second_number == 1 || second_number == 2 || second_number == 3 || second_number == 4 || second_number == 5)
            {
                if (sum == 0)
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (count == 15)
    {
        if (first_number == 3)
        {
            if (second_number == 4 || second_number == 7)
            {
                if (sum == 0)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

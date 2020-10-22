#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Get's the best amount of change for user
int main(void)
{
    float change = 0;
    while (true)
    {
        // Get the change from the user
        change = get_float("Change Owed: ");

        if (change > 0)
        {
            break;
        }
    }
    // Initialize Variables
    int coins = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int cents = round(change * 100);
    // Count the change required
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    while (pennies > 0)
    {
        pennies++;
        pennies = cents - 1;
    }
    if (cents == 1)
    {
        pennies++;
    }
    // Get the total # of coins
    coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}

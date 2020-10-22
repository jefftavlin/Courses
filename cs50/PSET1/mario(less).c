#include <stdio.h>
#include <cs50.h>

// Prints out a mario Pyramid

int main(void)
{
    int height;
    while (true)
    {
        // Get the height from the user
        height = get_int("Height: ");

        // if condition to check whether between 1 and 8
        if ((height >= 1) && (height <= 8))
        {
            break;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int z = height - 1; z > i; z--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

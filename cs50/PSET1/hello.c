#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get_string get's input from a user.
    string name = get_string("What's your name?\n");
    printf("hello, %s\n", name);
}

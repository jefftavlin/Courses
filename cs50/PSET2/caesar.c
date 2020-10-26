#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int ValidArgv(string command_text);
string Encryption(int key, string text);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int valid_key = ValidArgv(argv[1]);

        if (valid_key == 0)
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            string encrypted = Encryption(key, plaintext);
            printf("ciphertext: %s\n", encrypted);
        }

        else
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key");
        return 1;
    }
}

int ValidArgv(string command_text)
{
    int valid;

    for (int i = 0; i < strlen(command_text); i++)
    {
        if (isdigit(command_text[i]))
        {
            valid = 0;
        }
        else
        {
            valid = 1;
        }
    }
    return valid;
}


string Encryption(int key, string text)
{

    for (int i = 0; i < strlen(text); i++)
    {
        if (isupper(text[i]))
        {
            text[i] = (text[i] + key - 65) % 26 + 65;
        }
        else if (islower(text[i]))
        {
            text[i] = (text[i] + key - 97) % 26 + 97;
        }
    }
    return text;
}

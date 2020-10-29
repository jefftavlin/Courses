#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int AlphaCheck(string command_text);
int RepeatCheck(string command_text);
string Encryption(string command_text, string plaintext);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            int alpha_check = AlphaCheck(argv[1]);
            if (alpha_check == 0)
            {
                char copy[26] = "";
                strcpy(copy, argv[1]);

                int repeat_check = RepeatCheck(copy);
                if (repeat_check == 26)
                {
                    string plain_text = get_string("Plaintext: ");
                    char output[strlen(plain_text) + 1];
                    output[strlen(plain_text)] = '\0'; // inputs the null character the array
                    string key = argv[1];

                    for (int i = 0; i < strlen(plain_text); i++)
                    {
                        if (plain_text[i] >= 'A' && plain_text[i] <= 'Z')
                        {
                            int index_position = plain_text[i] - 'A'; // gets the index position of the plaintext
                            output[i] = toupper(key[index_position]);
                        }
                        else if (plain_text[i] >= 'a' && plain_text[i] <= 'z')
                        {
                            int index_position = plain_text[i] - 'a';
                            output[i] = tolower(key[index_position]);
                        }
                        else
                        {
                            output[i] = plain_text[i];
                        }
                    }
                    printf("ciphertext: %s\n", output);
                }

                else
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
            else
            {
                printf("Key must contain only alphabetical characters.\n");
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
}

int AlphaCheck(string command_text)
{
    int valid;

    for (int i = 0; i < strlen(command_text); i++)
    {
        if (isdigit(command_text[i]))
        {
            valid = 1;
        }
    }
    return valid;
}

int RepeatCheck(string command_text)
{
    int count = 0;

    for (int i = 0; i < strlen(command_text); i++)
    {
        command_text[i] = tolower(command_text[i]);
    }

    for (int j = 0; j < strlen(command_text); j++)
    {
        for (int z = 0; z < strlen(command_text); z ++)
        {
            if (command_text[j] == command_text[z])
            {
                count++;
            }
        }
    }
    return count;
}

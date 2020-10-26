#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int CountingLetters(string word);
int CountingWords(string word);
int CountingSentences(string word);

int main(void)
{
    string text = get_string("Text: ");

    // Run the 3 helper functions
    int letters = CountingLetters(text);
    int words = CountingWords(text);
    int sentences = CountingSentences(text);

    // Calculate the Index
    float L = (letters / (double) words * 100);
    float S = (sentences / (double) words * 100);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (round(index < 1))
    {
        printf("Before Grade 1\n");
    }
    else if (round(index > 16))
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

int CountingLetters(string word)
{
    int count = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(word[i]))
        {
            count++;
        }
    }
    return count;
}

int CountingWords(string word)
{

    int count = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        if (word[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

int CountingSentences(string word)
{
    int count = 0;
    int n = strlen(word);

    for (int i = 0; i < n; i++)
    {
        if (word[i] == '.' || word[i] == '!' || word[i] == '?')
        {
            count++;
        }
    }
    return count;
}

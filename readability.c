#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void printGrade(int index);

int main(void)
{
    string text = get_string("Text: ");

    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float l = (letters / words) * 100.0;
    float s = (sentences / words) * 100.0;

    float index = 0.0588 * l - 0.296 * s - 15.8;
    int final_index = (int) round(index);

    printGrade(final_index);

    return 0;
}

// counting the letters of the text
int count_letters(string text)
{
    int letter_count = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}

// counting the words of the text
int count_words(string text)
{
    int word_count = 1;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            word_count++;
        }
    }
    return word_count;
}

// counting the sentences of the text
int count_sentences(string text)
{
    int count_s = 0;
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_s++;
        }
    }
    return count_s;
}

// Simplified grade printing
void printGrade(int index)
{
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

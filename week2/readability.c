#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text:  ");
    // Count the no of characters in text for for loop.
    int characters = strlen(text);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Traversing through the text
    for (int i = 0; i < characters; i++)
    {
        // Letter is any lowercase character from a to z or any uppercase character from A to Z
        if (text[i] >= 'A' && text[i] <= 'z')
        {
            letters++;
        }
        // Sequence of characters separated by spaces should count as a word
        if (text[i] == ' ')
        {
            words++;
        }
        // Cccurrence of a period, exclamation point, or question mark indicates the end of a sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    float avg_letter = (letters / (float) words) * 100;
    float avg_sentence = (sentences / (float) words) * 100;
    // Coleman-Liau index is computed
    float index = 0.0588 * avg_letter - 0.296 * avg_sentence - 15.8;

    if (index >= 16.0000)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1.0000)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade  %i\n", (int) round(index));
    }

}
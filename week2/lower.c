#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("No command line arguments were given or more than one arguments were given\n");
        return -1;
    }

    string word = argv[1];

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            printf("%c", word[i] + 32);
        }
        else
        {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}
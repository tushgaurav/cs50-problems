#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Tushar", "Gaurav", "Sasha", "Bill", "David", "Kumar"};
    string search_term = "Tushar";

    for (int i = 0; names[i] != NULL; i++)
    {
        if (strcmp(names[i], search_term) == 0)
        {
            printf("Found at %i position\n", i);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
// Linear Search
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[] = {4, 2, 6, 1, 9, 5, 3};
    int search_term = 4;

    for (int i = 0; numbers[i] != '\0'; i++)
    {
        if (numbers[i] == search_term)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
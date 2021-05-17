#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Tushar";
    people[0].number = "+917870218562";

    people[1].name = "Rinku";
    people[1].name = "100";

    // Loop searches for "Tushar"
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, "Tushar") == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
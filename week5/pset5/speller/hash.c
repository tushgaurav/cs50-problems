#include <stdio.h>

int easyhash(char *word);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./hash [word]\n");
        return 1;
    }

    printf("Digest is: %i\n", easyhash(argv[1]));
}

int easyhash(char *word)
{
    int tem = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        tem = tem + word[i];
    }
    int digest = tem % 70;
    return digest;
}
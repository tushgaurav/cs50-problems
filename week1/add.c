#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = get_int("Enter a number: ");
    int b = get_int("Enter a number: ");
    
    printf("%i\n", a + b);
}
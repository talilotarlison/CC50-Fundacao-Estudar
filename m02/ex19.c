#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Argumento ausente\n");
        return 1;
    }
    printf("oi, %s\n", argv[1]);
    return 0;
}
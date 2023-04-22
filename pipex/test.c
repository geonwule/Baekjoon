#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = malloc(10);
    strcpy(input, "HELLO");
    printf("%s\n", input);
    //free(input);
    //printf("%s\n", input);
    input = ralloc(input, 20);
    strcat(input, "WORLD");
    printf("%s\n", input);
}
#include <stdio.h>
#include <string.h>

int main()
{
    char *str = "aaaaaa\nbbbbb\ncccc\n";
    
    char *ptr = strchr(str, '\n');
    printf("ptr = \n----%s\n----", ptr);
}
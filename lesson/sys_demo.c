#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Using system function for running ps program.\n");
    system("cat /home/codespace/secret");
    printf("ps completed\n");
    return 0;
}
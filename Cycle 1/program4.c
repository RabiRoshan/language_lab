#include <stdio.h>
#include <string.h>
void main()
{
    char input[100];
    printf("Enter the string\n");
    scanf("%s", input);
    int state = 1;
    int pos = 0;
    for (pos = 0; pos < strlen(input); pos++)
    {
        if ((input[pos] == 'a' || input[pos] == 'c') && state == 1)
            state = 1;
        else if (input[pos] == 'b' && state == 1)
            state = 2;
        else if ((input[pos] == 'a' || input[pos] == 'b') && state == 2)
            state = 1;
        else if (input[pos] == 'c' && state == 2)
            state = 3;
        else if ((input[pos] == 'a' || input[pos] == 'b' || input[pos] == 'c') && state == 3)
            state = 3;
        else
        {
            printf("\ninvalid\n");
            return;
        }
    }

    if (state == 3)
        printf("\nvalid\n");
    else
        printf("\ninvalid\n");
}
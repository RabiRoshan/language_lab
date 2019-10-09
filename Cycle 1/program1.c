#include <stdio.h>
#include <string.h>
int main()
{
    char input[100];
    printf("Enter the string:\t");
    scanf("%s", input);
    int state = 1;
    int pos = 0;
    for (pos = 0; pos < strlen(input); pos++)
    {
        if (input[pos] == 'b' && state == 1)
            state = 1;
        else if (input[pos] == 'a' && state == 1)
            state = 2;
        else if (input[pos] == 'a' && state == 2)
            state = 2;
        else if (input[pos] == 'b' && state == 2)
            state = 3;
        else if (input[pos] == 'a' && state == 3)
            state = 2;
        else if (input[pos] == 'b' && state == 3)
            state = 4;
        else if (input[pos] == 'a' && state == 4)
            state = 2;
        else if (input[pos] == 'b' && state == 4)
            state = 1;
        else
        {
            printf("invalid\n");
            return 1;
        }
    }

    if (state == 4)
        printf("valid\n");
    else
        printf("invalid\n");

    return 1;
}

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
    if (input[pos] == '1' && state == 1)
      state = 1;
    else if (input[pos] == '0' && state == 1)
      state = 2;
    else if (input[pos] == '1' && state == 2)
      state = 1;
    else if (input[pos] == '0' && state == 2)
      state = 3;
    else if (input[pos] == '1' && state == 3)
      state = 1;
    else
    {
      printf("\ninvalid");
      return;
    }
  }

  if (state == 1)
    printf("\nvalid\n");
  else
    printf("\ninvalid\n\n");
}

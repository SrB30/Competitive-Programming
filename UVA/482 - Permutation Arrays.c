#include <stdio.h>
#include <string.h>
#define max 1000
int pos[max];
char arr[max][max];
int main()
{
  int t, i, index, cnt, j = 0;

  scanf("%d\n", &t);

  while (t--)
  {
      if (j > 0)    printf("\n");
      j = 1;

      cnt = 0;

      while (1)
      {
          scanf("%d", &index);
          pos[index-1] = cnt++;

          if (getchar() == '\n')
              break;
      }

      for (i = 0; i < cnt; i++)
          scanf("%s", arr[i]);

      for (i = 0; i < cnt; i++)
          printf("%s\n", arr[pos[i]]);


  }

  return 0;
}

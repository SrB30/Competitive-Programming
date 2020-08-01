#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 55
int top = -1;
char stack[max];

int precedence(char c)
{
    switch(c)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    default:
        return 1;
    }
}
void push(char c)
{
    stack[++top] = c;
    return;
}

char pop(void)
{
    char item = stack[top--];
    return item;
}

int main()
{
    char pfx[65], c, d, ig;
    char infx[55][3];
    int t, i=0, j, k;
    scanf("%d%*c%*c", &t, &ig, &ig);

    while (++i <= t)
    {
        push('(');

        j=0, k=0;
        do
        {
            gets(infx[j]);
            c = infx[j][0];

            if (isdigit(c))
                pfx[k++] = c;

            else if (c == '(')
                push(c);

            else if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
            {
                while (precedence(stack[top]) >= precedence(c))
                {
                    pfx[k++] = pop();
                }
                push(c);
            }

            else if (c == ')' || c == '\0')
            {
                while(stack[top] != '(')
                    pfx[k++] =pop();

                d = pop();
            }
            pfx[k] = '\0';
        }
        while (infx[j++][0] != '\0');

        printf("%s\n", pfx);

        if (i < t)
            printf("\n");
    }

    return 0;
}



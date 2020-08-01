#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n;
    char ig, c;
    char *stack = (char*) malloc(sizeof(char)*130);

    scanf("%d%*c", &n, &ig);

    while (n--)
    {
        int top= -1;
        t=0;

        do
        {
            scanf("%c", &c);

            if(t>-1 && c!= '\n')
            {
                if (c=='[' || c=='(')
                    stack[++top] = c;

                else if(top != -1 && (c==']' || c==')'))
                {
                    if((c==']' && stack[top]=='[') || (c==')' && stack[top]=='('))
                        top--;
                }

                else if ((c==']' || c==')'))
                    t = -1;
            }
        }
        while (c != '\n');

        if(t==-1 || top!=-1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}

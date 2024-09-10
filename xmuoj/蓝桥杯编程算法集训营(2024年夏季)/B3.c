#include <stdio.h>

int stack[10000];
int top = -1;
void push(int x) { stack[++top] = x; }
void pop() { top--; }

int main()
{
    int n;
    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (-1 == top)
        {
            printf("-1 ");
            push(x);
        }
        else if (x > stack[top])
        {
            printf("%d ", stack[top]);
            push(x);
        }
        else // x <= stack[top]
        {
            while (x <= stack[top] && top > -1) pop();

            if (top == -1) printf("-1 ");
            else printf("%d ", stack[top]);

            push(x);
        }
    }

    return 0;
}
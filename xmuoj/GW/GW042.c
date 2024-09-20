#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    char p1[10], p2[10];
    while (n--)
    {
        scanf("%s%s", p1, p2);

        if (*p1 == *p2) printf("Tie\n");
        else
        {
            if (*p1 == 'R')
            {
                if (*p2 == 'S') printf("Player1\n");
                else printf("Player2\n");
            }
            else if (*p1 == 'S')
            {
                if (*p2 == 'R') printf("Player2\n");
                else printf("Player1\n");
            }
            else
            {
                if (*p2 == 'R') printf("Player1\n");
                else printf("Player2\n");
            }
        }
    }

    return 0;
}
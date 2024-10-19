#include <stdio.h>

int main()
{
    int s;
    char num[11];
    
    char print1[10] = {1, 0, 1, 1, 0, 1, 1, 1, 1, 1};
    char print2[10] = {2, 1, 1, 1, 2, 0, 0, 1, 2, 2};
    char print3[10] = {0, 0, 1, 1, 1, 1, 1, 0, 1, 1};
    char print4[10] = {2, 1, 0, 1, 1, 1, 2, 1, 2, 1};
    char print5[10] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1};

    int f = 0;
    while (scanf("%d%s", &s, num) != EOF && s && (num[0] != '0' || num[1]))
    {
        if (!f) f = 1; else printf("\n");

        char *p = num;
        while (*p)
        {
            printf(" ");
            if (print1[*p - '0']) for (int i = 0; i < s; i++) printf("-"); else for (int i = 0; i < s; i++) printf(" ");
            printf(" ");
            p++;
            if (*p) printf(" ");
        }
        printf("\n");

        
        for (int i = 0; i < s; i++)
        {
            p = num;
            while (*p)
            {
                if (print2[*p - '0'] != 1) printf("|"); else printf(" ");
                for (int j = 0; j < s; j++) printf(" ");
                if (print2[*p - '0'] != 0) printf("|"); else printf(" ");
                p++;
                if (*p) printf(" ");
            }
            printf("\n");
        }

        p = num;
        while (*p)
        {
            printf(" ");
            if (print3[*p - '0']) for (int i = 0; i < s; i++) printf("-"); else for (int i = 0; i < s; i++) printf(" ");
            printf(" ");
            p++;
            if (*p) printf(" ");
        }
        printf("\n");

        
        for (int i = 0; i < s; i++)
        {
            p = num;
            while (*p)
            {
                if (print4[*p - '0'] != 1) printf("|"); else printf(" ");
                for (int j = 0; j < s; j++) printf(" ");
                if (print4[*p - '0'] != 0) printf("|"); else printf(" ");
                p++;
                if (*p) printf(" ");
            }
            printf("\n");
        }

        p = num;
        while (*p)
        {
            printf(" ");
            if (print5[*p - '0']) for (int i = 0; i < s; i++) printf("-"); else for (int i = 0; i < s; i++) printf(" ");
            printf(" ");
            p++;
            if (*p) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char line[20010];
    gets(line);

    int max = 0, min = 101, maxIdx = -1, minIdx = -1;

    int len = 0;
    int flag = isalpha(line[0]);
    int i;
    for (i = 0; line[i]; i++)
    {
        if (!isalpha(line[i]) && flag)
        {
            flag = 0;
            if (len > max) max = len, maxIdx = i - len;
            if (len < min) min = len, minIdx = i - len;
            len = 0;
        }
        else if (isalpha(line[i]) && !flag) flag = 1, len = 1;
        else if (isalpha(line[i]) && flag) len++;
    }

    if (len > max) max = len, maxIdx = i - len;
    if (len < min) min = len, minIdx = i - len;

    for (i = maxIdx; i < maxIdx + max; i++) putchar(line[i]);
    putchar('\n');
    for (i = minIdx; i < minIdx + min; i++) putchar(line[i]);

    return 0;
}
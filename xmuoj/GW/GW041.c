#include <stdio.h>

int main()
{
    char str[100010];
    scanf("%s", str);

    char alphabet[26];
    for (int i = 0; i < 26; i++) alphabet[i] = -1;

    for (int i = 0; str[i]!= '\0'; i++)
    {
        if (alphabet[str[i] - 'a'] == -1) alphabet[str[i] - 'a'] = i;
        else if (alphabet[str[i] - 'a'] != -1) alphabet[str[i] - 'a'] = -2;
    }

    int idx = -1;
    for (int i = 0; i < 26; i++)
    {
        if (idx == -1 && alphabet[i] >= 0) idx = alphabet[i];
        else if (idx != -1 && alphabet[i] >= 0 && alphabet[i] < idx) idx = alphabet[i];
    }

    if (idx == -1) printf("no");
    else printf("%c", str[idx]);

    return 0;
}
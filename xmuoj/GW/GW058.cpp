// 代码填空题

double GetDoubleFromString(char * str)
{
// 在此处补充你的代码
    static char *p = str;
    p = (NULL == str ? p : str);

    double ret = 0.0;

    int flag = 0, flag2 = 0, flag3 = 1;
    int x = 1;
    while (*p && flag3)
    {
        if (!flag)
        {
            if ('0' <= *p && '9' >= *p) flag = 1, ret += *p - '0';
        }
        else
        {
            if (!flag2)
            {
                if ('0' <= *p && '9' >= *p) ret *= 10, ret += *p - '0';
                else if ('.' == *p) flag2 = 1;
                else flag3 = 0;
            }
            else
            {
                if ('0' <= *p && '9' >= *p)
                {
                    double d = *p - '0';
                    for (int i = 0; i < x; i++) d /= 10;
                    x++;
                    ret += d;
                }
                else flag3 = 0;
            }
        }
        
        p++;
    }

    return (ret == 0 ? -1.0 : ret);
}
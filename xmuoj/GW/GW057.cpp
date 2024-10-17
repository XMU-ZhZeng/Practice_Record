// 代码填空题

// 在此处补充你的代码
void mysort(void* base, int sizeOfNum, int sizeOfElem, int (*compare)(const void *, const void *))
{
    if (sizeOfNum <= 1) return;

    // 快速排序
    char tmp[sizeOfElem];
    for (int i = 0; i < sizeOfElem; i++) tmp[i] = *((char*)base + i);

    char *l = (char*)base, *r = (char*)base + (sizeOfNum - 1) * sizeOfElem;

    while (l < r)
    {
        while (compare(r, tmp) >= 0 && r != l) r -= sizeOfElem;
        for (int i = 0; i < sizeOfElem; i++) l[i] = r[i];
        while (compare(l, tmp) < 0 && r != l) l += sizeOfElem;
        for (int i = 0; i < sizeOfElem; i++) r[i] = l[i];
    }
    for (int i = 0; i < sizeOfElem; i++) r[i] = tmp[i];

    int lNum = (r - (char*)base) / sizeOfElem;
    mysort(base, lNum, sizeOfElem, compare);
    mysort(r + sizeOfElem, sizeOfNum - lNum - 1, sizeOfElem, compare);
}

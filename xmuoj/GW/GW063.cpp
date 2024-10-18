// 程序填空题

// 在此处补充你的代码
struct Rule1 { bool operator()(int e1, int e2)
{
    return (e1 % 10 == e2 % 10 ? e1 > e2 : e1 % 10 < e2 % 10);
} };

struct Rule2 { bool operator()(Point& e1, Point& e2)
{
    int l1 = e1.x * e1.x + e1.y * e1.y, l2 = e2.x * e2.x + e2.y * e2.y;
    return (l1 != l2 ? l1 < l2 : (e1.x != e2.x ? e1.x < e2.x : e1.y < e2.y));
} };
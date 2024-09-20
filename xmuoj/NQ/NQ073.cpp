#include <iostream>
using namespace std;
#include <string>

double RPN()
{
    string s;
    cin >> s;
    if (s == "+" || s == "-" || s == "*" || s == "/")
    {
        double a = RPN();
        double b = RPN();
        if (s == "+") return a + b;
        if (s == "-") return a - b;
        if (s == "*") return a * b;
        if (s == "/") return a / b;
    }
    else
    {
        return stod(s);
    }
}

int main()
{
    printf("%lf\n", RPN());
    return 0;
}
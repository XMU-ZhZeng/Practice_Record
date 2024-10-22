#include <iostream>
using namespace std;
#include <algorithm>
#include <string>

double func(string& str, int size) // 状态机递归计算表达式，size：0：表达式，1：项，2：因子
{  
  if (0 == size) // 处理表达式
  {
    double res = 0.0;

    string term;
    int count = 0; // 统计“(”“)”的数量
    char _operator = '+';

    for (auto it : str)
    {
      if ('(' == it) count++;
      else if (')' == it) count--;

      if (count)
      {
        term += it;
      }
      else
      {
        if ('+' == it || '-' == it)
        {
          if ('+' == _operator) res += func(term, 1);
          if ('-' == _operator) res -= func(term, 1);
          term.clear();
          _operator = it;
        }
        else
        {
          term += it;
        }
      }
    }

    if ('+' == _operator) res += func(term, 1);
    if ('-' == _operator) res -= func(term, 1);

    return res;
  }
  else if (1 == size) // 处理项
  {
    double res = 1.0;

    string factor;
    int count = 0; // 统计“(”“)”的数量c
    char _operator = '*';

    for (auto it : str)
    {
      if ('(' == it) count++;
      else if (')' == it) count--;

      if (count)
      {
        factor += it;
      }
      else
      {
        if ('*' == it || '/' == it)
        {
          if ('*' == _operator) res *= func(factor, 2);
          if ('/' == _operator) res /= func(factor, 2);
          factor.clear();
          _operator = it;
        }
        else
        {
          factor += it;
        }
      }
    }

    if ('*' == _operator) res *= func(factor, 2);
    if ('/' == _operator) res /= func(factor, 2);

    return res;
  }
  else // 处理因子
  {
    if ('(' == str[0])
    {
      string expression(str.begin() + 1, str.end() - 1);
      return func(expression, 0);
    }
    else
    {
      return stof(str);
    }
  }
  return 0.0;
}

int main()
{
  // 获取表达式
  string expression;
  cin >> expression;

  printf("%d", (int)func(expression, 0));

  return 0;
}
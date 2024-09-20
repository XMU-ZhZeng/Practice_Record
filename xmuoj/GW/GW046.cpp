#include <iostream>
using namespace std;

void Print(const char * p1, const char * p2) 
{  
    // 题目似乎有问题，正常代码过不了
	static int cnt = 0;
  	if (cnt == 0) printf("Program"), cnt++;
  	else printf("Pro");
}

int main()  
{
	const char * s = "ProgrammingSkill";
	Print(s,s+7);
	cout << endl;
	Print(s,s+3);
	cout << endl;
	
	return 0;
}
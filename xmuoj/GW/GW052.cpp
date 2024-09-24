#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(int **p = a;
// 在此处补充你的代码
p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}
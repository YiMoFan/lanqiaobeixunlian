/*题目描述

 在一个直角坐标系中有一条线段，求这条线段上有几个整数点；
输入

输入一个数T(T<10000)，表示有T组测试数据； 
每组数据输入有四个整数x1, y1, x2, y2，表示线段的两端点坐标；
(-1e16<=x1,x2,y1,y2<=1e16)
输出

 输出一个整数，表示这条线段上整数点个数；
样例输入

2
1 1 5 5
1 3 4 12
样例输出

5
4
*/
#include "stdio.h"

int gcd(long long int a,long long int b) {
	return b == 0 ? a : gcd(b,a % b);
}

int main ( ) {
	int T;
	scanf ("%d",&T);
	while (T--) {
		long long int x1,y1,x2,y2;
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		int temp1,temp2;
		if (x1 >= x2)
			temp1 = x1 - x2;
		else 
			temp1 = x2 - x1;
		if (y1 >= y2)
			temp2 = y1 - y2;
		else 
			temp2 = y2 - y1;
//		int temp1 = abs(x1-x2);
//		int temp2 = abs(y1-y2);
		if (temp1 == 0 && temp2 == 0)
			printf ("1\n");
		else 
			printf ("%d\n",gcd(temp1,temp2) + 1);
	}
	
	return 0;
}



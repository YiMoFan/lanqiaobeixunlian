/*题目内容：
 找出n个自然数（1,2···n）中取r个数的组合，例如当n=5，r=3时所有组合为
1 2 3 
1 2 4
1 2 5
1 3 4
1 3 5
1 4 5
2 3 4
2 3 5
2 4 5
3 4 5
此题只需求出组合数的个数
输入描述
输入两个正整数n、r

输出描述
计算出n个自然数中取r个数的组合数的个数

输入样例
5 3
20 18

输出样例
10
190
*/

//公式水过 
#include "stdio.h"

int jiecheng(int n,int r) {
	long long sum = 1;
	for (int i = n; i >= r; i--) {
		sum = sum * i;
	}
	
	return sum;
}

int main () {
	int n,r;
	scanf("%d %d",&n,&r);
	printf ("%d",jiecheng(n,r+1) / jiecheng(n-r,1));
	
	return 0;
}



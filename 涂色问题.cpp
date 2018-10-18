/*题目内容：
 有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法。
输入描述
输入正整数n

输出描述
输出结果

输入样例
5

输出样例
30*/


#include "stdio.h"

int main () {
	int n1 = 3,n2 = 6,n3 = 6;
	int n;
	int ans = 0;
	scanf ("%d",&n);
	if (n <= 3) {
		if ( n == 1) 
			printf ("%d",n1);
		else 
			printf ("%d",n2);
	}
	else {
		int temp1 = n2;
		int temp2 = n3;
		for (int i = n - 3 ; i > 0 ; i--) {
			ans = temp2 + temp1 * 2;
			temp1 = temp2;
			temp2 = ans;
		}
		printf ("%d",ans);
	}
	
	return 0;
}

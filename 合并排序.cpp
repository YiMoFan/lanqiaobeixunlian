/*题目内容：
 使用合并排序算法，对输入的n个数据进行按升序排序。
输入描述
分两行，第一行是整数n,第二行是n个整数，每个整数之间用空格间隔。

输出描述
按升序排序的n个整数

输入样例
8
9 8 7 6 5 4 3 2

输出样例
2 3 4 5 6 7 8 9*/


#include "stdio.h"

int main () {
	int n;
	int num[1000];
	scanf ("%d",&n);
	for (int i = 0; i < n ; i ++ )
		scanf ("%d",&num[i]);
	for (int i = 1; i <= n-1; i++) {
		for (int j = 0; j < n-1; j++) {
			if (num[j] > num[j+1]) {
				int temp;
				temp = num[j];
				num[j] = num[j+1];
				num[j+1] = temp;
			}
		}
	}
	
	for (int i = 0; i < n ; i ++) {
		if (i == 0) 
			printf ("%d",num[i]);
		else 
			printf (" %d",num[i]);
	} 
	
	return 0;
} 

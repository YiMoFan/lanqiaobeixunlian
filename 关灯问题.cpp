/*题目内容：
一百个灯泡排成一排，第一轮将所有灯泡打开；
第二轮每隔一个灯泡关掉一个。即排在偶数的灯泡被关掉，
第三轮每隔两个灯泡，将开着的灯泡关掉，关掉的灯泡打开。
依次类推，第n轮结束的时候，还有几盏灯泡亮着。
输入描述
程序输入n( 0 < n < 101)

输出描述
输出亮的灯数。

输入样例
2

输出样例
50
*/

#include "stdio.h"

int main () {
	int n;
	int a[101]; 
	scanf ("%d",&n);
	for (int i = 1; i < 101; i++) 
		a[i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 101; j = j + i) {
			if (a[j])
				a[j] = 0;
			else 
				a[j] = 1;
		}
	}
	
	int count = 0;
	for (int i = 1; i < 101; i++) 
		if (a[i])
			count++;
	
	printf ("%d",count);
	
	return 0;
}


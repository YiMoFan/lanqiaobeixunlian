/*题目内容：
如果有一正整数n，其真因数的总和等于n，则称之为完美数。
例如以下几个数都是完美数：
6=1+2+3
28=1+2+4+7+14
496=1+2+4+8+16+31+62+124+248
求小于n的所有完美数.
 
输入描述
输入一个正整数n

输出描述
输出小于n的完美数，按升序输出，每个数据占一行

输入样例
10

输出样例
6
*/

#include "stdio.h"

int panduan(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++) {
		if (n % i == 0)
			sum += i;
	}
	
	return sum == n ? 1 : 0;
}

int main () {
	int n;
	scanf ("%d",&n);
	for (int i = 2; i <= n; i++) {
		if (panduan(i))
			printf ("%d\n",i);
	}
	
	return 0;
}


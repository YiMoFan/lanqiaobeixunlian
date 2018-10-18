/*题目内容：
设I是一个n位十进制整数.如果将I划分为k段,则可得到k个整数.这k个整数的乘积称为I的一个k乘积.试设计一个算法,
对于给定的I和k ,求出I的最大k乘积.
Input
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个n位十进制整数.（n<=10）
Output
输出计算结果，第1行中的数是计算出的最大k乘积.
n位十进制整数.（n<=10）
输入描述
输入的第1行中有2个正整数n和k.正整数n是序列的长度;正整数k是分割的段数.接下来的一行中是一个

输出描述
输出计算结果，第1行中的数是计算出的最大k乘积.

输入样例
2 1
15

输出样例
15
*/

#include "stdio.h"

const int M = 11;

int max(int n,int m) {
	return n > m ? n : m; 
}

int main () {
	int ws,k,n;
	scanf ("%d %d %d",&ws,&k,&n);
	if (k == 1)
		printf ("%d",n);
	else {
		int nik[M][M];
		int dp[M][M];
		for (int i = 1 ; i <= ws ; i++) {
			int temp = 10;
			for (int j = i ; j <= ws ; j++) {
				nik[i][j] = n % temp;
				temp = temp * 10;
			}
			n = n / 10;
		}
		for (int i = 1 ; i <= ws ; i++)
			dp[i][1] = nik[1][i];
		for (int i = 2; i <= k; i++) {
			for (int j = 1; j <= ws; j++) {
				int maxn = 0;
				for (int k = 1 ; k < j; k++) 
					maxn = max(dp[k][i-1]*nik[k+1][j],maxn);
					
				dp[j][i] = maxn;
			}
		}
		printf ("%d",dp[ws][k]);
	}
	
	return 0;
} 

 

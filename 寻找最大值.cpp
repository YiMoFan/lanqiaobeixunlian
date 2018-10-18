/*题目内容：
请在整数 n 中删除m个数字, 使得余下的数字按原次序组成的新数最大，
比如当n=92081346718538，m=10时，则新的最大数是9888
输入描述
第一行输入一个正整数T，表示有T组测试数据每组测试数据占一行，每行有两个
数n,m（n可能是一个很大的整数，但其位数不超过100位，并且保证数据首位非0，m小于整数n的位数）

输出描述
每组测试数据的输出占一行，输出剩余的数字按原次序组成的最大新数

输入样例
2
92081346718538 10
1008908 5

输出样例
9888
98
*/

#include "stdio.h"
#include "string.h"

int main () {
	int T;
	scanf ("%d",&T);
	while (T--) {
		char s[100],a[100];
		int N;
		memset(s,'\0',sizeof(s));
		scanf ("%s %d",s,&N);
		int num = strlen(s) - N;
		int temp = 0;
		int max = 0;
		memset(a,'\0',sizeof(a));
		while (num--) {
			for (int i = max + 1; i < strlen(s) - num; i++) {
				if (s[i] > s[max])
					max = i;
			}
			a[temp++] = s[max];
			max++;
		}
		for (int i = 0; i < temp; i++)
			printf("%c",a[i]);
		printf ("\n");
	}
	
	return 0;
}


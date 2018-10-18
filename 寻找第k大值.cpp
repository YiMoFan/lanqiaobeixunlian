/*题目内容：
 在一个整数数组中，寻找第k大值所在位置。假设每个数值都不一样。要求算法时间复杂性通常情况下为线性。
输入描述
包括一个数组长度n,一个k, 以及紧接着的n个整数值。整数之间用空格隔开。

输出描述
第k大值所在位置编号。规定数组的第一个位置编号为0.

输入样例
7 3
1 4 3 9 8 7 2

输出样例
5
*/

#include "stdio.h"
#include "iostream"
#include <algorithm>

using namespace std;

int main () {
	int n,k;
	int arr[100];
	int temp[100];
	scanf ("%d %d",&n,&k);
	for (int i = 0; i < n; i++)	{
		scanf ("%d",&arr[i]);
		temp[i] = arr[i];
	}
	
	sort(arr,arr+n);
	int flag = arr[n-k];
	for (int i = 0; ; i++) {
		if (temp[i] == flag) {
			printf ("%d",i);
			break;
		}
	}
	
	return 0;
} 


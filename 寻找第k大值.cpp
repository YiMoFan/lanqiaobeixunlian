/*��Ŀ���ݣ�
 ��һ�����������У�Ѱ�ҵ�k��ֵ����λ�á�����ÿ����ֵ����һ����Ҫ���㷨ʱ�临����ͨ�������Ϊ���ԡ�
��������
����һ�����鳤��n,һ��k, �Լ������ŵ�n������ֵ������֮���ÿո������

�������
��k��ֵ����λ�ñ�š��涨����ĵ�һ��λ�ñ��Ϊ0.

��������
7 3
1 4 3 9 8 7 2

�������
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


/*��Ŀ���ݣ�
 ʹ�úϲ������㷨���������n�����ݽ��а���������
��������
�����У���һ��������n,�ڶ�����n��������ÿ������֮���ÿո�����

�������
�����������n������

��������
8
9 8 7 6 5 4 3 2

�������
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

/*��Ŀ���ݣ�
 �ҳ�n����Ȼ����1,2������n����ȡr��������ϣ����統n=5��r=3ʱ�������Ϊ
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
����ֻ�����������ĸ���
��������
��������������n��r

�������
�����n����Ȼ����ȡr������������ĸ���

��������
5 3
20 18

�������
10
190
*/

//��ʽˮ�� 
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



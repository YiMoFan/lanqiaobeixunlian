/*��Ŀ���ݣ�
 ���ų�һ�еģ�������ú�(Red)����(Pink)����(Green)��ɫͿÿ�����ӣ�ÿ��Ϳһɫ��Ҫ���κ����ڵķ�����ͬɫ������β����Ҳ��ͬɫ����ȫ��������Ҫ���Ϳ����
��������
����������n

�������
������

��������
5

�������
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

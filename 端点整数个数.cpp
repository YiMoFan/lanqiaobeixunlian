/*��Ŀ����

 ��һ��ֱ������ϵ����һ���߶Σ��������߶����м��������㣻
����

����һ����T(T<10000)����ʾ��T��������ݣ� 
ÿ�������������ĸ�����x1, y1, x2, y2����ʾ�߶ε����˵����ꣻ
(-1e16<=x1,x2,y1,y2<=1e16)
���

 ���һ����������ʾ�����߶��������������
��������

2
1 1 5 5
1 3 4 12
�������

5
4
*/
#include "stdio.h"

int gcd(long long int a,long long int b) {
	return b == 0 ? a : gcd(b,a % b);
}

int main ( ) {
	int T;
	scanf ("%d",&T);
	while (T--) {
		long long int x1,y1,x2,y2;
		scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
		int temp1,temp2;
		if (x1 >= x2)
			temp1 = x1 - x2;
		else 
			temp1 = x2 - x1;
		if (y1 >= y2)
			temp2 = y1 - y2;
		else 
			temp2 = y2 - y1;
//		int temp1 = abs(x1-x2);
//		int temp2 = abs(y1-y2);
		if (temp1 == 0 && temp2 == 0)
			printf ("1\n");
		else 
			printf ("%d\n",gcd(temp1,temp2) + 1);
	}
	
	return 0;
}



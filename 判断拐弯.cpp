/*��Ŀ���ݣ�
 С�����ֻ������������Ⱥ󾭹��������ص�A, B, C������,�������ж�С����B��������䣬�����ҹ���
��������
A, B, C������

�������
left  ���� right

��������
0,0
1,1
2,1

�������
right
*/

#include "stdio.h"

int main () {
	double x1,y1;
	double x2,y2;
	double x3,y3;
	scanf ("%lf,%lf\n%lf,%lf\n%lf,%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	if (x2 == x1) {  //б�ʲ����� 
		if (x3 > x2) printf ("right");
		else printf ("left"); 
	}
	else if (y2 == y1) {  //б��Ϊ�� 
		if (x2 > x1) {
			if (y3 < y2) printf ("right");
			else printf ("left");
		}
		else {
			if (y3 < y2) printf ("right");
			else printf ("left");
		}
	}
	else {  //б�ʴ����Ҳ�Ϊ�� 
		double k = (double)(y2-y1) / (x2-x1);
		double temp = (double)(x1-x2)*y3 - (double)(y1-y2)*x3 - (double)(x1-x2)*y2 + (double)(y1-y2)*x2;
		if (k > 0)
			if (temp > 0) printf ("right");
			else printf ("left");
		else 
			if (temp > 0) printf ("left");
			else printf ("right");
	}
	
	return 0;
}


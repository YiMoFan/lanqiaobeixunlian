/*��Ŀ���ݣ�
 ������������ȡ����Ϸ��һ����M���ƣ�ÿ�ο���ȡ1,2,����5�ţ�ȡ�����һ���Ƶ���Ϊʤ��������ж���ȡ�Ƶ��Ƿ���ʤ����
��������
����M

�������
Y����N

��������
2

�������
Y
*/

#include "stdio.h"

int main () {
	int m;
	int num[1000];
	scanf ("%d",&m);
	num[1] = 1;
	num[2] = 1;
	num[3] = 0;
	num[4] = 1;
	num[5] = 1;
	for (int i = 6; i <= m; i++) {
		if (num[i-1] && num[i-2] && num[i-5])
			num[i] = 0;
	}
	if (num[m]) printf ("Y");
	else printf ("N");
	
	return 0;
}


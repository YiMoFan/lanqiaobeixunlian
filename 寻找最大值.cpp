/*��Ŀ���ݣ�
�������� n ��ɾ��m������, ʹ�����µ����ְ�ԭ������ɵ��������
���統n=92081346718538��m=10ʱ�����µ��������9888
��������
��һ������һ��������T����ʾ��T���������ÿ���������ռһ�У�ÿ��������
��n,m��n������һ���ܴ������������λ��������100λ�����ұ�֤������λ��0��mС������n��λ����

�������
ÿ��������ݵ����ռһ�У����ʣ������ְ�ԭ������ɵ��������

��������
2
92081346718538 10
1008908 5

�������
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


/*��Ŀ���ݣ�
����һ��������n�Ļ��֣����ǰ�n���һϵ��������֮�͵ı��ʽ��ע�⣬�ֻ���˳���޹أ�����6=5+1��6=1+5��
ͬһ�ַֻ������⣬���������������Ҳ��һ�ַֻ���
���磺����������n=5�����Ի���Ϊ��
1+1+1+1+1
1+1+1+2
1+1+3
1+2+2
2+3
1+4
5
��������
����һ��������n

�������
���n�������ֵ�����k

��������
5

�������
7
*/

#include<iostream>

using namespace std;

int Divinteger(int n,int m) {
	if(n == 1||m == 1)
		return 1;
	else if(n < m)
		return Divintege(n,n);
	else if(n == m)
		return 1+Divintege(n,n-1);
	else
		return Divintege(n,m-1) + Divintege(n-m,m);
}


int main(void) {
	int n;
	while(scanf("%d",&n) != EOF && (n >= 1)) {
		printf("%d\n",Divintege(n,n));
	}
	
	return 0;
}

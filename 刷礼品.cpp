/*��Ŀ���ݣ�
 һ��һ�ȵİٶ�֮���ֿ�ʼ�ˣ���β������������˼���˹�����¼�����ǰٶ�֮
 �Ǿ�������һ�����ˣ������ʸ����ύID��x��β�Ĳ���ѡ�ֽ��õ�������Ʒһ�ݡ�
	СС��ͬѧ�ǳ���õ������Ʒ���������������ύ�˺ܶ�Σ��ύID��a������b��
	�������������ܵõ����ٷ���Ʒ�����ܰ������
��������
��һ��һ��������T��ʾ����������
����ȥT�У�ÿ������������x��a��b (0<=x<=10^18�� 1<=a��b <=10^18��a<= b)

�������
T�У�ÿ��Ϊ��Ӧ����������£�СС�ȵõ�����Ʒ��

��������
1
88888 88888 88888

�������
1
*/
#include "stdio.h" 
int main() {  
	int n;  
	long long int x,a,b;  
	scanf ("%d",&n);  
	while (n--) {  
		scanf("%lld%lld%lld",&x,&a,&b);  
		if (x == 0) 
			printf ("%lld\n",((b-b%10)-(a-a%10))/10 );  
		else {  
			long long int tmpx = x;  
			int i = 1;  
			do{  
				i *= 10;  
			}while (tmpx = tmpx/10);  
			long long int body = ((b-b%i)-(a-a%i))/i;  
			long long int tmpa = a%i;  
			long long int tmpb = b%i;  
			int tmp1 = tmpb>=x? 1:0;  
			int tmp2 = tmpa> x?-1:0;  
  
  
			printf("%lld\n",body+tmp1+tmp2 );  
		}  
	} 
	
	return 0;  
} 

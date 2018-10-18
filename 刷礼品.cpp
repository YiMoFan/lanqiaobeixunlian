/*题目内容：
 一年一度的百度之星又开始了，这次参赛人数创下了吉尼斯世界纪录，于是百度之
 星决定奖励一部分人：所有资格赛提交ID以x结尾的参赛选手将得到精美礼品一份。
	小小度同学非常想得到这份礼品，于是他就连续提交了很多次，提交ID从a连续到b，
	他想问问你他能得到多少份礼品，你能帮帮他吗？
输入描述
第一行一个正整数T表示数据组数；
接下去T行，每行三个正整数x，a，b (0<=x<=10^18， 1<=a，b <=10^18，a<= b)

输出描述
T行，每行为对应的数据情况下，小小度得到的礼品数

输入样例
1
88888 88888 88888

输出样例
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

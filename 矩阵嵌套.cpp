/*��Ŀ���ݣ�
��n�����Σ�ÿ�����ο�����a,b����������ʾ���Ϳ�����X(a,b)����Ƕ���ھ�
��Y(c,d)�е��ҽ���a<c,b<d����b<c,a<d���൱����תX90�ȣ������磨1,5������
Ƕ���ڣ�6,2���ڣ�������Ƕ���ڣ�3,4���С����������ѡ�������ܶ�ľ����ų�
һ�У�ʹ�ó����һ���⣬ÿһ�����ζ�����Ƕ������һ�������ڡ�
��������
��һ����һ��������N(0<N<10)����ʾ��������������ÿ��������ݵĵ�һ����һ��
������n����ʾ������������к��о��εĸ���(n<=1000)����n�У�ÿ����������a,b(0<a,b<100)����ʾ���εĳ��Ϳ�

�������
ÿ��������ݶ����һ��������ʾ�����������ľ�����Ŀ��ÿ�����ռһ��

��������
1
10
1 2
2 4
5 8
6 10
7 9
3 1
5 8
12 10
9 7
2 2

�������
5
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct stu {
	int a,b;
}s[1020];

int dp[1020];

int cmp(stu x,stu y) {
	if(x.a<y.a)
		return 1;
	else if(x.a==y.a&&x.b<y.b)
		return 1;
	else
		return 0;
}

int main() {
	int t,i;
	scanf("%d",&t);
	while(t--) {
		int n,j,ans;
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d%d",&s[i].a,&s[i].b);
			if(s[i].a<s[i].b)
			swap(s[i].a,s[i].b);
		}
		sort(s,s+n,cmp);
		ans=0;
		for(i=0;i<n;i++) {
			dp[i]=1;
			for(j=0;j<i;j++) {
				if(s[j].a<s[i].a&&s[j].b<s[i].b)
				dp[i]=max(dp[i],dp[j]+1);
			}
		ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}


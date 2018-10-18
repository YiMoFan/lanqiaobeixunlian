/*题目内容：
有n个矩形，每个矩形可以用a,b来描述，表示长和宽。矩形X(a,b)可以嵌套在矩
形Y(c,d)中当且仅当a<c,b<d或者b<c,a<d（相当于旋转X90度）。例如（1,5）可以
嵌套在（6,2）内，但不能嵌套在（3,4）中。你的任务是选出尽可能多的矩形排成
一行，使得除最后一个外，每一个矩形都可以嵌套在下一个矩形内。
输入描述
第一行是一个正正数N(0<N<10)，表示测试数据组数，每组测试数据的第一行是一个
正正数n，表示该组测试数据中含有矩形的个数(n<=1000)随后的n行，每行有两个数a,b(0<a,b<100)，表示矩形的长和宽

输出描述
每组测试数据都输出一个数，表示最多符合条件的矩形数目，每组输出占一行

输入样例
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

输出样例
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


/*题目内容：
背包最大允许装载为C, 有n个物品要放进背包，每个物品的重量为w[1],w[2],...w[n],每个物品的价值为v[1],v[2],...v[n], 请选择物品装进背包，使得价值最大。C为整数。
输入描述
第一行为物体个数n,以及背包容量C；
第二行为n个重量（实数），空格隔开
第三行为n个价值（实数），空格隔开

输出描述
第一行为最大装载的总价值
第二行为每个物品是否装载，1表示装，0表示不装，中间用空格隔开
(测试数据能保证最优解唯一)

输入样例
5 10
2 2 6 5 4
6 3 5 4 6

输出样例
15
1 1 0 0 1
*/

#include<stdio.h>  
#define M 100

int n,c;  
int w[M],p[M];  
int m[M][M];  
int x[M];  

int min(int a,int b) {
	return a <= b ? a : b;
}

int max(int a,int b) {
	return a >= b ? a : b;
}

void Knapsack(int v[],int w[],int c,int n,int m[M][M])  
{  
    int jMax;  
    int i,j;  
    jMax = min(w[n] - 1,c);  
    for(j = 0;j <= jMax; j++)  
        m[n][j] = 0;  
    for(j = w[n];j <= c; j++)  
        m[n][j] = v[n];  
    for(i = n - 1;i > 1; i--)  
    {  
        jMax = min(w[i] - 1,c);  
        for(j = 0;j <= jMax; j++)  
            m[i][j] = m[i + 1][j];  
        for(j = w[i];j <= c; j++)  
            m[i][j] = max(m[i + 1][j],m[i + 1][j - w[i]] + v[i]);  
    }  
    m[1][c] = m[2][c];  
    if(c >= w[1])  
        m[1][c] = max(m[1][c],m[2][c - w[1]] + v[1]);  
}  
  
void Traceback(int m[M][M],int w[],int c,int n,int x[])  
{  
    int i;  
    for(i = 1;i < n; i++)  
    {  
        if(m[i][c] == m[i + 1][c])  
            x[i] = 0;  
        else  
        {  
            x[i] = 1;  
            c = c - w[i];  
        }  
    }  
    x[n] = (m[n][c])?1:0;   
}  
  
int main()  
{  
    int i;  
    scanf("%d",&n);  
    scanf("%d",&c);  
    for(i = 1;i <= n; i++)  
        scanf("%d",&w[i]);  
    for(i = 1;i <= n; i++)  
        scanf("%d",&p[i]);  
    Knapsack(p,w,c,n,m);  
    Traceback(m,w,c,n,x);  
  
    printf("%d\n",m[1][c]);//输出最优价值和  
    for(i = 1;i <= n; i++)//输出01序列  
        printf("%d ",x[i]);  
    printf("\n");  
    return 0;  
} 


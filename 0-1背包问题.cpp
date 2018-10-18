/*��Ŀ���ݣ�
�����������װ��ΪC, ��n����ƷҪ�Ž�������ÿ����Ʒ������Ϊw[1],w[2],...w[n],ÿ����Ʒ�ļ�ֵΪv[1],v[2],...v[n], ��ѡ����Ʒװ��������ʹ�ü�ֵ���CΪ������
��������
��һ��Ϊ�������n,�Լ���������C��
�ڶ���Ϊn��������ʵ�������ո����
������Ϊn����ֵ��ʵ�������ո����

�������
��һ��Ϊ���װ�ص��ܼ�ֵ
�ڶ���Ϊÿ����Ʒ�Ƿ�װ�أ�1��ʾװ��0��ʾ��װ���м��ÿո����
(���������ܱ�֤���Ž�Ψһ)

��������
5 10
2 2 6 5 4
6 3 5 4 6

�������
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
  
    printf("%d\n",m[1][c]);//������ż�ֵ��  
    for(i = 1;i <= n; i++)//���01����  
        printf("%d ",x[i]);  
    printf("\n");  
    return 0;  
} 


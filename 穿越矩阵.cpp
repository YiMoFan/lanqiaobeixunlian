/*��Ŀ���ݣ�
 ������һ�� m * n ���������������дһ����������һ�������Ҵ��������·������ʹ��·���ķ�����С��·���Ӿ�������ĵ�һ�е����ⵥԪ��ʼ���𲽴������󵽴����Ҳ��һ�е����ⵥԪ��ÿһ����ָ��ĳ��Ԫ�������һ�е����ڵ�Ԫ������ͼ�������Ǻ����б�򣩡�����ĵ�һ�к����һ��ʵ�������ڵģ��������������ǰ�����һ����ŵ�Բ�������棨������Ҫ���� 
·���Ļ�����ָ����·������Խ�����е�Ԫ���е�����֮�͡�
��������
�������һϵ�о���������ÿ�����������ĵ�һ���� m �� n���������������������֮��� m �У�ÿ�а��� n ���Կո�ֿ������������ǵ�ǰ�����ֵ��ע������ֵδ���������� 
��������� m ������ n �ķ�Χ�ǣ�1 <=m<=10�� 1<=n<=100������·���ķ���ֵ�������� 30bit ��������ʾ��

�������
���ÿһ�������ҳ�������С��·���������������ÿ�����������������У���һ����·�����������ÿһ�����ڵ��У��ڶ������Ǹ�·���ķ��á� 
�������ͬһ�������ж�����ͬ�ķ�����С·�������������кŽ�С��һ����

��������
5 6
3 4 1 2 8 6
6 1 8 2 7 4
5 9 3 9 9 5
8 4 1 3 2 6
3 7 2 1 2 3

�������
1 2 1 5 4 5
11
*/

#include<stdio.h>    
#include<string.h>    
int dp[11][101], a[11][101], num[101] = { 0 };    
#define INF 0x3f3f3f3f    
int min(int a, int b)    
{    
    return a < b ? a : b;    
}    
int main()    
{    
    int n, m;    
    while (scanf("%d%d", &n, &m) != EOF)    
    {    
        memset(dp, INF, sizeof(dp));    
        memset(num, 0, sizeof(num));    
        for (int i = 0; i < n; i++)    
        for (int j = 0; j < m; j++)    
            scanf("%d", &a[i][j]);    
        for (int i = 0; i < n; i++)    
            dp[i][m - 1] = a[i][m - 1];    
        for (int i = m - 2; i >= 0; i--)    
        for (int j = 0; j < n; j++)    
        {    
            dp[j][i] = a[j][i];    
            if (j>0 && j < n - 1)    
                dp[j][i] += min(min(dp[j][i + 1], dp[j + 1][i + 1]), dp[j - 1][i + 1]);    
            else if (j == 0)    
                dp[j][i] += min(min(dp[j][i + 1], dp[j + 1][i + 1]), dp[n - 1][i + 1]);    
            else if (j == n - 1)    
                dp[j][i] += min(min(dp[j][i + 1], dp[0][i + 1]), dp[j - 1][i + 1]);    
        }    
        int mini, mine = dp[n - 1][0];    
        for (int i = n - 1; i >= 0; i--)    
        if (mine >= dp[i][0])    
        {    
            mine = dp[i][0];    
            mini = i;    
        }    
        num[0] = mini;    
        for (int i = 1; i < m; i++)    
        {    
            int flag = 0;    
            for (int j = 0; j < n; j++)    
            {    
                if (mini == 0 && j != 0 && j != 1 && j != n - 1)    
                    continue;    
                if (mini == n - 1 && j != n - 1 && j != n - 2 && j != 0)    
                    continue;    
                if (mini>0 && mini < n - 1 && j != mini&&j != mini + 1 && j != mini - 1)    
                    continue;    
                if (dp[mini][i - 1] - a[mini][i - 1] == dp[j][i])    
                {    
                    mini = j;    
                    num[i] = mini;    
                    flag = 1;    
                }    
                if (flag)    
                    break;    
            }    
        }    
        printf("%d", num[0]+1);    
        for (int i = 1; i < m; i++)    
            printf(" %d", num[i]+1);    
        printf("\n%d\n", mine);    
    }    
    return 0;    
}  


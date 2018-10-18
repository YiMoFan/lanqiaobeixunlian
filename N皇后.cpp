/*题目内容：
 国际象棋中的皇后可以沿着水平线，垂直线，或者斜线前进，吃掉遇到的所有棋子，如果棋盘上有八个皇后，则这八个皇后如何相安无事的
放置在棋盘上，1970年与1971年， E.W.Dijkstra与N.Wirth曾经用这个问题来讲解程式设计之技巧。
该题要求N皇后的放置结果共有多少种
输入描述
输入一个正整数N（N小于16）

输出描述
输出结果

输入样例
8

输出样例
92
*/

#include<stdio.h>  
#include<iostream>  
#include<string.h>  
  
using namespace std;  
  
int n,tmp;  
int map[11];  
  
void DFS(int k)  
{  
    int i,j,flag;  
    if(k==n+1)  
    {  
        tmp++;  
        return;  
    }  
    else  
    {  
        for(i=1;i<=n;++i)  
        {  
            map[k]=i;  
            flag=1;  
            for(j=1;j<k;++j)  
            {  
                if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j)///注：i=map[k];不在同一条斜线的两点的含义是行标到对角线的的距离不相等  
                {  
                    flag=0;  
                    break;  
                }  
            }  
            if(flag)  
                DFS(k+1);  
        }  
    }  
}  
  
int main()  
{  
    int i,m;  
    int ans[11];  
    for(n=1;n<=10;++n)  
    {  
        tmp=0;  
        DFS(1);  
        ans[n]=tmp;  
    }  
    scanf("%d",&m);
	printf("%d",ans[m]);  
    
	return 0;  
}  


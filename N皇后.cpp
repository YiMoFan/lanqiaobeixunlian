/*��Ŀ���ݣ�
 ���������еĻʺ��������ˮƽ�ߣ���ֱ�ߣ�����б��ǰ�����Ե��������������ӣ�����������а˸��ʺ�����˸��ʺ�����ల���µ�
�����������ϣ�1970����1971�꣬ E.W.Dijkstra��N.Wirth��������������������ʽ���֮���ɡ�
����Ҫ��N�ʺ�ķ��ý�����ж�����
��������
����һ��������N��NС��16��

�������
������

��������
8

�������
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
                if(map[j]==i||i-k==map[j]-j||i+k==map[j]+j)///ע��i=map[k];����ͬһ��б�ߵ�����ĺ������б굽�Խ��ߵĵľ��벻���  
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


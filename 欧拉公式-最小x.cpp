/*��Ŀ���ݣ�
 ����һ��n, ������ 2^x =1 (mod n)����Сx.
��������
��������n

�������
�����С��x, ��������������ڡ�

��������
5

�������
4
*/

#include<stdio.h>  
int main()  
{  
    int x,t,n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        if(n==1||n%2==0)  
        printf("������\n");  
        else  
        {  
            x=1;  
            t=2;  
            while(t%n!=1)  
            {  
                x++;  
                t=t*2%n;  
            }  
            printf("%d\n",x);  
        }  
    }  
    return 0;  
} 

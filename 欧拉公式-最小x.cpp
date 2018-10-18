/*题目内容：
 给定一个n, 求满足 2^x =1 (mod n)的最小x.
输入描述
输入整数n

输出描述
输出最小的x, 或者输出“不存在”

输入样例
5

输出样例
4
*/

#include<stdio.h>  
int main()  
{  
    int x,t,n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        if(n==1||n%2==0)  
        printf("不存在\n");  
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

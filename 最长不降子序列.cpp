/*题目内容：
所谓子序列，就是在原序列里删掉若干个元素后剩下的序列，
以字符串"abcdefg"为例子，去掉bde得到子序列"acfg"现在的问题是，
给你一个数字序列，你要求出它最长的单调不降子序列。
输入描述
多组测试数据，每组测试数据第一行是n(1<=n<=10000)，表示n个数据，
下一行是n个比10^9小的正整数

输出描述
对于每组测试数据输出一行，每行内容是最长的单调不降子序列
的长度

输入样例
5
1 2 4 8 16
5
1 10 4 9 7
9
0 0 0 1 1 1 5 5 5

输出样例
5
3
9
*/

#include<stdio.h>  
#define N 100  
  
int fun(int a[],int n){  
    int num[N];  
    int i,j;  
    for(i=0;i<n;i++){      
        num[i]=1;  
        for(j=0;j<i;j++){  
            //if(a[j]<=a[i])  
            if(a[j]<=a[i]&&num[j]+1>=num[i])
                num[i]=num[j]+1;  
        }  
    }  
    int max=0;  
    for(i=0;i<n;i++)  
        if(max<num[i])  
            max=num[i];    
    return max;  
}  
int main(){  
    int a[N],n,i;  
    scanf("%d",&n);  
    for(i=0;i<n;i++){  
        scanf("%d",&a[i]);  
    }  
    printf("%d",fun(a,n));  
    return 0;  
}  

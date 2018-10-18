/*题目内容：
 一个从里向外逆时针转出来的螺旋n*n的矩阵 输
输入描述
矩阵的规模，0~50，如5表示5行5列的矩阵

输出描述
矩阵的规模，0~50，如5表示5行5列的矩阵，每个数占5位

输入样例
5

输出样例
25    24   23   22    21
10     9    8    7    20
11     2    1    6    19
12     3    4    5    18
13    14   15   16    17
*/

#include <stdio.h>

int main(){  
    int n, k = 0;  
    scanf("%d", &n);  
    //定义动态二维数组  
    int **a = new int*[n];//n行  
    int i,j;  
    for(i=0;i<n;++i)//行  
        a[i] = new int[n];//列  
  
    int sum = n * n;  
    while(k <= n / 2 ) {  
        for(j = k; j <= n-k-1; j++)  
            a[k][j] = sum--;  
        for(i = k+1; i <= n-k-1; i++)  
            a[i][n-k-1] = sum--;  
        for(j = n-k-2; j >= k; j--)  
            a[n-k-1][j] = sum--;  
        for(i = n-k-2; i >= k+1; i--)  
            a[i][k] = sum--;
        k++;  
    }  
      
    for(i = 0; i < n; i++) {  
        for(j = 0; j < n; j++)  
            if(j == 0)  
                printf("%d",a[i][j]);  
            else  
                printf("%5d",a[i][j]);  
        printf("\n");  
      
    }  
    return 0;  
} 


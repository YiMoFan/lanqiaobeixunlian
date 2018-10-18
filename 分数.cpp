/*题目内容：
 写出一个程序，接受一个以N/D的形式输入的分数，其中N为分子，D为分母，输出它的小数形式。

本题中，0≤N≤65535，0<D≤65535，设运算结果小数点后最多保留100位。
输入描述
分别输入N D

输出描述
如果它的小数形式存在循环，则要将其循环节用括号括起来。例如：
1/3= 0.(3)

输入样例
1 7

输出样例
0.(142857)
*/
#include<iostream>  
using namespace std;  
  
int *f(int n, int d) {  
    int i = 1, *c = new int [d]();    
    static int a[103];  
  
    while(n%d != 0 && i != 100){  
        if(c[n%d] != -1)  
            c[n%d] = -1;  
        else{  
            a[0]=-2;  
            break;  
        }  
        a[i] = n / d;  
        n %= d;  
        n *= 10;  
        ++i;  
    }  
    a[i] = n / d;  
    if(a[0] != -2){  
        a[0]=-1;  
        a[i+1]=-1;  
    }  
    else  
        a[i+1]=-2;  
	return a;
}  
  
int main() {  
    int n, d, i=1, *a;  
    cin>> n >> d;  
    a=f(n,d);  
    while(i != 100 && a[i] >= 0){  
        if(i == 2)  
            if(a[0] == -2)  
                cout<<"."<<"(";  
            else  
                cout<<".";  
        cout<<a[i];  
        ++i;  
    }  
    if(a[0] == -2) cout<<")";  
        return 0;  
}

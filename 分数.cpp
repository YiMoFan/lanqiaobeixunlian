/*��Ŀ���ݣ�
 д��һ�����򣬽���һ����N/D����ʽ����ķ���������NΪ���ӣ�DΪ��ĸ���������С����ʽ��

�����У�0��N��65535��0<D��65535����������С�������ౣ��100λ��
��������
�ֱ�����N D

�������
�������С����ʽ����ѭ������Ҫ����ѭ���������������������磺
1/3= 0.(3)

��������
1 7

�������
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

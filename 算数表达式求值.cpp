/*
Author : xiong

题目内容：
 输入一个由数字、+，-，*，/ 组成的算术表达式，求其值。
输入描述
一个表达式，其中每个运算数为正整数

输出描述
计算结果，保留2位小数

输入样例
1+12*3-4/2 

输出样例
35.00

*/

#include <iostream>
#include <cstdio>
using namespace std;

double Shu[100];
char Fu[100];
int numOfFu;

int main()
{
	numOfFu = 0;
	int num = 0;
	char ch = getchar();
	while(ch != EOF)
	{
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			Fu[numOfFu] = ch;
			Shu[numOfFu++] = num;
			num = 0;
		}
		else if(ch>='0' && ch <='9')
		{
			num = num * 10 + (ch - '0');
		}
		ch = getchar();
	}
	Shu[numOfFu] = num;
	
	for(int i = 0; i < numOfFu; i++)
	{
		if(Fu[i] == '*' )
		{
			Shu[i] *= Shu[i+1];
			Shu[i+1] = Shu[i]; 
		}
		else if(Fu[i] == '/')
		{
			Shu[i] /= Shu[i+1];
			Shu[i+1] = Shu[i]; 
		}
	}
	
	for(int i = 0; i < numOfFu; i++)
	{
		if(Fu[i] == '*' )
		{
			Shu[i+1] = Shu[i]; 
		}
		else if(Fu[i] == '/')
		{
			Shu[i+1] = Shu[i]; 
		}
		else if(Fu[i] == '+')
		{
			Shu[i] += Shu[i+1];
			Shu[i+1] = Shu[i]; 
		}
		else if(Fu[i] == '-')
		{
			Shu[i] -= Shu[i+1];
			Shu[i+1] = Shu[i]; 
		}
	}
	printf("%.2lf\n",Shu[numOfFu]);
}

/*Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，
你不得不再次走上坡或者等待升降机来载你。Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。
数组的每个数字代表点的高度。下面是一个例子 
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。
当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。
输入描述
输入的第一行表示区域的行数R和列数C(1<=R,C<=100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

输出描述
输出最长区域的长度。

输入样例
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

输出样例
25*/


#include "stdio.h"

int h[101][101];  // 输入高度值 
int dis_sk[101][101];  //记录每个点可以滑行的最大距离 
int index[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};  //方向数组 
int r,c;  // 记录行和列 

int panduan(int i,int j) {  //判断是否越界的辅助函数 
	if (i >= 0 &&i < r && j >= 0 && j < c)
		return 1;
	else 
		return 0;
}

int dis(int i,int j) {
	int temp;
	if ( dis_sk[i][j] )   //已经求出来，直接返回 
		return dis_sk[i][j];
	for (int k = 0; k < 4; k++) {  //试探每个方向 
		if (panduan(i+index[k][0],j+index[k][1])) {  //如果没有越界 
			if (h[i][j] > h[i+index[k][0]][j+index[k][1]]) {  
				temp = dis(i+index[k][0],j+index[k][1]);  //递归求dis_sk[i+index[k][0]][j+index[k][1]]，并存放在temp中 
				dis_sk[i][j] = dis_sk[i][j] > temp ? dis_sk[i][j] : temp + 1; 
			}
		}
	}
	
	return dis_sk[i][j];
}

int main () {
	int max_dis = 0;
	scanf ("%d %d",&r,&c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf ("%d",&h[i][j]);
			dis_sk[i][j] = 0;
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int temp = dis(i,j);
			max_dis = max_dis > temp ? max_dis : temp;
		}
	}
	printf ("%d",max_dis+1);
	
	return 0;
}

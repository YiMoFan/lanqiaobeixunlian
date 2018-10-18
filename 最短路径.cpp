/*题目内容：
 有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。
 计算从城市A到其他任意城市的最短路径距离。
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行是D到E的直达距离。

输出描述
A城市到(B,C,D,E)的最短距离。

输入样例
2 3 4 5  
3 4 2 
4 3   
3

输出样例
2 3 4 4
*/


#include "stdio.h"

int main () {
	int e[10][10],dis[10],book[10];
	int n = 5;
	int min,u,v;
	int inf = 999999999;
	//初始化 
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j++) 
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
	// 读入数据，读入边 
	for (int i = 1; i <= 4; i++) {
		for (int j = i+1; j <= 5; j++) {
			int temp;
			scanf ("%d",&temp);
			e[i][j] = temp;
		}
	}
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程 
	for (int i = 1; i <= 5; i++)
		dis[i] = e[1][i];
	//book数组初始化 
	for (int i = 1; i <= n ; i++)
		book[i] = 0;
	book[1] = 1;
	//Dijkstra算法核心语句 
	for (int i = 1; i <= n-1; i++) {
		min = inf;
		//找到离1号顶点最近的顶点 
		for (int j = 1; j <= n; j++) {
			if (book[j] == 0 && dis[j]  < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1 ; v <= n; v++) {
			if (e[u][v] < inf) {
				if (dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}
	}
	//输出结果 
	for (int i = 2 ; i <= n; i++)
		if (i == 2) 
			printf ("%d",dis[i]);
		else 
			printf (" %d",dis[i]);
	
	return 0;
}


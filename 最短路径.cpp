/*��Ŀ���ݣ�
 ��5������(A,B,C,D,E),����ÿ�����е��������е�ֱ�������֪����������֮��ֻ��һ����·��
 ����ӳ���A������������е����·�����롣
��������
4�����ݣ� ��һ����A��(B,C,D,E)��ֱ����룬�ڶ�����B����C,D,E����ֱ����룬����������4����D��E��ֱ����롣

�������
A���е�(B,C,D,E)����̾��롣

��������
2 3 4 5  
3 4 2 
4 3   
3

�������
2 3 4 4
*/


#include "stdio.h"

int main () {
	int e[10][10],dis[10],book[10];
	int n = 5;
	int min,u,v;
	int inf = 999999999;
	//��ʼ�� 
	for (int i = 1; i <= n; i ++) 
		for (int j = 1; j <= n; j++) 
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
	// �������ݣ������ 
	for (int i = 1; i <= 4; i++) {
		for (int j = i+1; j <= 5; j++) {
			int temp;
			scanf ("%d",&temp);
			e[i][j] = temp;
		}
	}
	//��ʼ��dis���飬������1�Ŷ��㵽�����������ĳ�ʼ·�� 
	for (int i = 1; i <= 5; i++)
		dis[i] = e[1][i];
	//book�����ʼ�� 
	for (int i = 1; i <= n ; i++)
		book[i] = 0;
	book[1] = 1;
	//Dijkstra�㷨������� 
	for (int i = 1; i <= n-1; i++) {
		min = inf;
		//�ҵ���1�Ŷ�������Ķ��� 
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
	//������ 
	for (int i = 2 ; i <= n; i++)
		if (i == 2) 
			printf ("%d",dis[i]);
		else 
			printf (" %d",dis[i]);
	
	return 0;
}


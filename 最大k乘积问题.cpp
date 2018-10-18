/*��Ŀ���ݣ�
��I��һ��nλʮ��������.�����I����Ϊk��,��ɵõ�k������.��k�������ĳ˻���ΪI��һ��k�˻�.�����һ���㷨,
���ڸ�����I��k ,���I�����k�˻�.
Input
����ĵ�1������2��������n��k.������n�����еĳ���;������k�Ƿָ�Ķ���.��������һ������һ��nλʮ��������.��n<=10��
Output
�������������1���е����Ǽ���������k�˻�.
nλʮ��������.��n<=10��
��������
����ĵ�1������2��������n��k.������n�����еĳ���;������k�Ƿָ�Ķ���.��������һ������һ��

�������
�������������1���е����Ǽ���������k�˻�.

��������
2 1
15

�������
15
*/

#include "stdio.h"

const int M = 11;

int max(int n,int m) {
	return n > m ? n : m; 
}

int main () {
	int ws,k,n;
	scanf ("%d %d %d",&ws,&k,&n);
	if (k == 1)
		printf ("%d",n);
	else {
		int nik[M][M];
		int dp[M][M];
		for (int i = 1 ; i <= ws ; i++) {
			int temp = 10;
			for (int j = i ; j <= ws ; j++) {
				nik[i][j] = n % temp;
				temp = temp * 10;
			}
			n = n / 10;
		}
		for (int i = 1 ; i <= ws ; i++)
			dp[i][1] = nik[1][i];
		for (int i = 2; i <= k; i++) {
			for (int j = 1; j <= ws; j++) {
				int maxn = 0;
				for (int k = 1 ; k < j; k++) 
					maxn = max(dp[k][i-1]*nik[k+1][j],maxn);
					
				dp[j][i] = maxn;
			}
		}
		printf ("%d",dp[ws][k]);
	}
	
	return 0;
} 

 

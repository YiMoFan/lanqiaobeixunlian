#include "stdio.h"

int main () {
	int num[1000] = {0};
	int n,k;
	int max = 0;
	scanf ("%d %d",&n,&k);
	for (int i = 0; i < n ; i++) {
		int temp;
		scanf ("%d",&temp);
		if (temp > max)
			max = temp;
		num[temp] ++;
	}
	int count = 1;
	for (int i = max ; i >= 1; i--) {
		if (count == k && num[i] != 0) {
			printf ("%d",num[i]);
			break;
		}
		if (num[i] != 0) {
			count++;
		}
	}
	
	return 0;
}

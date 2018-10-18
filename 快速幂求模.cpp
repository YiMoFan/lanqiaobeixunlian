#include "stdio.h"

int PowerMod(int a,int b,int c) {
	int ans = 1;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	
	return ans;
}

int main () {
	int a,b,c;
	while (scanf ("%d %d %d",&a,&b,&c) != EOF) {
		if (b == 0 && c == 1) 
			printf ("%d\n",1%c);
		else if (b == 0 && c != 1)
			printf ("%d\n",c);
		else 
			printf ("%d\n",PowerMod(a,b,c));
	}
	
	return 0;
}


/*题目内容：
 两个人玩轮流取牌游戏，一共有M张牌，每次可以取1,2,或者5张，取到最后一张牌的人为胜利。编程判断先取牌的是否能胜利。
输入描述
牌数M

输出描述
Y或者N

输入样例
2

输出样例
Y
*/

#include "stdio.h"

int main () {
	int m;
	int num[1000];
	scanf ("%d",&m);
	num[1] = 1;
	num[2] = 1;
	num[3] = 0;
	num[4] = 1;
	num[5] = 1;
	for (int i = 6; i <= m; i++) {
		if (num[i-1] && num[i-2] && num[i-5])
			num[i] = 0;
	}
	if (num[m]) printf ("Y");
	else printf ("N");
	
	return 0;
}


/*题目内容：
 两个乒乓球队进行比赛，各出三人。甲队为a，b，c三人，乙队为x，y，z三人。已抽签
决定比赛名单。共三场比赛，所有队员必须参加比赛。有人向队员打听比赛的名单，
a说他不和x比，c说他不和x，z比，请编程找出三场比赛赛手的名单。
输入描述
不需要输入

输出描述
假设a和y比，则输出
a vs y
严格按照上面的格式输出，不要有多余的文字叙述或符号，每场比赛输出占一行

输入样例
不需要输入

输出样例
a vs y
*/

#include "stdio.h"

int main () {
	for (char i = 'x'; i <= 'z'; i++) {
		for (char j = 'x'; j <= 'z'; j++) {
			if (i == j) continue;
			for (char k = 'x'; k <= 'z'; k++) {
				if (k == i || k == j) continue;
				if (i != 'x' && k != 'x' && k != 'z')
					printf ("a vs %c\nb vs %c\nc vs %c",i,j,k);
			}
		}
	}
	
	return 0;
}


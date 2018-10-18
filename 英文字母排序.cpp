/*题目内容：
编写一个程序，当输入英文字符串时，计算机将这个句子中的英文字母按字典字母顺序重新排列，排列后的单词的
长度要与原始句子中的长度相同，并且要求只对Ａ到Ｚ的字母重新排列，其它字符保持原来的状态。
输入描述
一个字符串，包括大写英文字母，以及其他字符

输出描述
字符串的重新排列，只是大写字母按字典顺序，其他字母保持原位

输入样例
ＴＨＥ ＰＲＩＣＥ ＯＦＢＲＥＡＤ ＩＳ ￥１ ２５ ＰＥＲ ＰＯＵＮＤ

输出样例
ＡＢＣ ＤＤＥＥＥ ＥＦＨＩＩＮＯ ＯＰ ￥１ ２５ ＰＰＲ ＲＲＳＴＵ*/

#include "stdio.h"

int main () {
	int str[100] = {0};
	char zhifu[10000] = {'\0'};
	char ch;
	int count = 0;
	while ((ch = getchar()) != '\n') {
		count++;
		if (ch >= 'A' && ch <= 'Z')
			str[ch]++;
		else {
			zhifu[count] = ch;
		}
	}
	for (int i = 1; i <= count; i ++) {
		if (zhifu[i] != '\0')
			printf ("%c",zhifu[i]);
		else {
			for (int j = 65; j <= 90; j++) {
				if (str[j] != 0) {
					printf ("%c",j);
					str[j]--;
					break;
				}
			}
		}
	}
	
	return 0;
} 

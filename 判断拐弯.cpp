/*题目内容：
 小张用手机传来他开车先后经过的三个地点A, B, C的坐标,请你编程判断小张在B点是左拐弯，还是右拐弯
输入描述
A, B, C的坐标

输出描述
left  或者 right

输入样例
0,0
1,1
2,1

输出样例
right
*/

#include "stdio.h"

int main () {
	double x1,y1;
	double x2,y2;
	double x3,y3;
	scanf ("%lf,%lf\n%lf,%lf\n%lf,%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	if (x2 == x1) {  //斜率不存在 
		if (x3 > x2) printf ("right");
		else printf ("left"); 
	}
	else if (y2 == y1) {  //斜率为零 
		if (x2 > x1) {
			if (y3 < y2) printf ("right");
			else printf ("left");
		}
		else {
			if (y3 < y2) printf ("right");
			else printf ("left");
		}
	}
	else {  //斜率存在且不为零 
		double k = (double)(y2-y1) / (x2-x1);
		double temp = (double)(x1-x2)*y3 - (double)(y1-y2)*x3 - (double)(x1-x2)*y2 + (double)(y1-y2)*x2;
		if (k > 0)
			if (temp > 0) printf ("right");
			else printf ("left");
		else 
			if (temp > 0) printf ("left");
			else printf ("right");
	}
	
	return 0;
}


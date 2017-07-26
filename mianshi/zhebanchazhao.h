/*
这个程序查找字符串中第一个空白字符前面的字符长度，没有仔细看不太懂2017年7月25日17:09:18
*/
#ifndef __ZHEBAN_H
#define __ZHEBAN_H
int mystrlen(char *buf, int N)
{
	if (buf[0] == 0 || N == 0)
		return 0;
	else if (N == 1)
		return 1;
	int t = mystrlen(buf, N / 2);
	if (t < N / 2)
		return t;
	else
		return (t + mystrlen(buf + N / 2, (N + 1) / 2));
}
#endif // !__ZHEBAN_H

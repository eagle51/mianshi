#ifndef __JIECHENG_H
#define __jIECHNEG_H
int jiecheng(int n)
{
	int i, val = 1;
	for (i = n;i > 0;i--)
	{
		val *= i;
	}
	return val;
}
#endif // !__JIECHENG_H

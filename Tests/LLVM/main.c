#include <stdlib.h>

static int apply(int (*) (int, int), int, int);
int apply(int (*func) (int, int), int a , int b)
{
	return func(a,b);
}

static int plus(int,int);
int plus(int a, int b)
{
	return a + b;
}

int main()
{
	int a = 1, b = 2;

	int result = apply(plus, a, b);

	return 0;
}
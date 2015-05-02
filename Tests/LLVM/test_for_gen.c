#include <stdio.h>

int main(int ac, char **av)
{
int i = 0;
int j = 2;
int k = 3;

k = i + j * k;

func(i,j);
}

int func(int a, int b)
{
return a + b;
}

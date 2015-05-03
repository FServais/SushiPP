#include <stdio.h>

int func(int argument);

int main(int ac, char **av)
{
    int i = 0;
    int j = 2;
    int k = 3;

    int p = k + i + j;

    int ret = func(p);
}

int func(int argument)
{
    int temp = argument+1;
    return temp;
}

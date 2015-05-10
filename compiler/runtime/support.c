#include "support.h"

#include <stdio.h>

void print_int(int64_t val)
{
	printf("%ld", val);
}

void print_float(float val)
{
	printf("%f", val);
}

void print_char(char val)
{
	printf("%c", val);
}

void print_bool(bool val)
{
	printf("%s", val ? "true" : "false");
}

void println_int(int64_t val)
{
	printf("%ld\n", val);
}

void println_float(float val)
{
	printf("%f\n", val);
}

void println_char(char val)
{
	printf("%c\n", val);
}

void println_bool(bool val)
{
	printf("%s\n", val ? "true" : "false");
}

int pow_int(uint64_t base, uint64_t exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return base;
	if(exp % 2) return base * pow_int(base, exp - 1);
	return pow_int(base * base, exp / 2); 
}

float pow_float(float base, uint64_t exp)
{
	if(exp == 0) return 1;
	if(exp == 1) return base;
	if(exp % 2) return base * pow_float(base, exp - 1);
	return pow_float(base * base, exp / 2); 
}
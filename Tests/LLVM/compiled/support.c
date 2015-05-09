#include "support.h"

#include <stdio.h>

void print_int(int64_t val)
{
	printf("%ld\n", val);
}

void print_float(float val)
{
	printf("%f\n", val);
}

void print_char(char val)
{
	printf("%c\n", val);
}

void print_bool(bool val)
{
	printf("%s\n", val ? "true" : "false");
}

void print_string(size_t string_id)
{
	printf("String id : %zu\n", string_id);
}


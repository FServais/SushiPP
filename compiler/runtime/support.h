#ifndef SUPPORT_HPP_DEFINED
#define SUPPORT_HPP_DEFINED

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

void print_int(int64_t val);
void print_float(float val);
void print_char(char val);
void print_bool(bool val);
void print_string(size_t string_id);

void println_int(int64_t val);
void println_float(float val);
void println_char(char val);
void println_bool(bool val);
void println_string(size_t string_id);

int pow_int(uint64_t base, uint64_t exp);
float pow_float(float base, uint64_t exp);

#endif // SUPPORT_HPP_DEFINED
/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my
*/

#include <stdarg.h>

#ifndef MY_H_
#define MY_H_

typedef struct params_s {
    char pad;
    char pad_val;
    int acc;
    char before;
    char sign;
    int output;
    char length_int;
    char length_char;
    char length_float;
} params_t;

void my_printf(char *, ...);
void my_putchar(char);
void my_putstr(char *);
void my_putstr_sized(char *, int);
void my_putstrfull(char *);
int my_strlen(const char *);
long long int my_getnbr(const char *);
char *my_strncpy(char *, char const *, int);
void print_pad(char *, int, char c);
char *my_strdup(char const *);
params_t *make_params(char *);
params_t *init_params(void);
params_t *get_length_tags(char *, params_t *);
char *my_nbr_to_str(long long int);
char *my_nbr_base_to_str(unsigned long long int, char const *);
char *my_float_to_str(long double, int);
void my_putnbr_sized(char *, int, params_t *);
char *my_strcat(char *, char *);
long long int get_int_with_length(va_list, params_t *);
unsigned long long int get_int_unsigned_with_length(va_list, params_t *);
long double get_float_with_length(va_list, params_t *);

void print_char(va_list, char *, params_t *);
void print_char_cap(va_list, char *, params_t *);
void print_str(va_list, char *, params_t *);
void print_nbr(va_list, char *, params_t *);
void print_octal(va_list, char *, params_t *);
void print_deci(va_list, char *, params_t *);
void print_hexa(va_list, char *, params_t *);
void print_hexa_cap(va_list, char *, params_t *);
void print_binairy(va_list, char *, params_t *);
void print_str_full(va_list, char *, params_t *);
void print_address(va_list, char *, params_t *);
void print_float(va_list, char *, params_t *);

#endif /* !MY_H_ */

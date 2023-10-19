#include <stdarg.h>
#ifndef _MAIN_H_
#define _MAIN_h_

/**
 * spec - structure for specifier
 * @a: the special char
 * @ptr: pointer to function that receivs the special char
 */
typedef struct spec
{
	char a;
	int (*ptr)(char *c);

} spec_t;
/*
typedef struct spec1
{
	char a;
	char *(*ptr)(int *);
} spec_i;
*/
/* FUNCTIONS USED IN MAIN ENTRY POIINT */
unsigned long int validate_input(const char *str);
long int fill_buffer(char *dest, unsigned long start, const char *src, unsigned long *c);
long int print_buffer(char *str);
long int print_special(char a);
long int specify(const char *format, unsigned long *c, va_list *list);
void escape(char *, unsigned long *);

int _printf(const char *format, ...);
long int print_char(char a);
long int print_string(char *str);
/* char *conv_int(int *); */
unsigned long int get_len(const char *format);

#endif /* _MAIN_H_ */

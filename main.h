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


int _printf(const char *format, ...);
unsigned int print_buffer(char *, unsigned int, unsigned int);
unsigned int specify(int (*)(char *), char *, char *, unsigned int *, unsigned int);
int print_char(char *);
int print_string(char *);
int print_percent(char *);
char *conv_int(int *);
unsigned int get_len(const char *format);

#endif /* _MAIN_H_ */

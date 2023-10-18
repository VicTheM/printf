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
cleanup(char *, va_list *);
validate_input(char *);
unsigned int fill_buffer(char *, unsigned int, char *, unsigned int *);
unsigned int print_buffer(char *);
unsigned int print_special(char);
unsigned int specify(char *, unsigned int *, va_list *);
escape(char *, unsigned int *);

int _printf(const char *format, ...);
unsigned int print_char(char *);
unsigned int print_string(char *)
char *conv_int(int *);
unsigned int get_len(const char *format);

#endif /* _MAIN_H_ */

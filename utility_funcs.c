#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"


/**
 * validate_input - a specialized strlen() function
 * @str: string buffer
 *
 * Return: len excluding special characters
 */
unsigned long int validate_input(const char *str)
{
	unsigned long int len;

	if (str == NULL || str[0] == '\0')
		return (0);
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * specify - Handles all variable sourcing after '%' sign
 * @format: format string containing the format specifier
 * @c: @format index
 * @list: contains all variables passed to _printf
 *
 * Return: num of characters in the printed variable
 */

long int specify(const char *format, unsigned long int *c, va_list *list)
{
	long int var_print;

	var_print = 0;
	if ((format[*c] > 64 && format[*c] < 91) ||
			(format[*c] > 96 && format[*c] < 123))
	{
		/* A character specifier was provided, no field width etc */
		switch (format[*c])
		{
			case 'c':
				var_print += print_char((char)va_arg(*list, int));
				break;
			case 's':
				var_print += print_string(va_arg(*list, char *));
				break;
		}
		(*c)++;
	}
	return (var_print);
}

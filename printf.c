#include "main.h"
#include <stdlib.h>
#include <stdarg.h>


/**
 * main_loop - main loop
 * @format: pointer to format string
 * @c: @format index
 * @buffer: buffer to hold pure chars from @format
 * @var_print: cummulative count of all variables printed
 * @tot_print: cummulative count of all strings printed
 * @list: va_list of all variable arguments in _printf
 *
 */
void main_loop(const char *format, unsigned long *c, char *buffer,
		unsigned long *var_print, unsigned long *tot_print, va_list *list)
{
	unsigned long nul, start;

	nul = start = 0;
	while (format[*c] != '\0')
	{
		if (!(format[*c] == '%' || format[*c] == '\\'))
		{
			nul += fill_buffer(buffer, start, format, c);
			*tot_print += print_buffer((buffer + start));
			start = nul;
		}
		if ((format[*c] == '%' && format[(*c) + 1] == '%') ||
				(format[*c] == '\\' && format[(*c) + 1] == '\\'))
		{
			*tot_print += print_special(format[(*c) + 1]);
			(*c) += 2;
		}
		else if (format[*c] == '%')
		{
			(*c)++;
			*var_print += specify(format, c, list);
		}
/*
 *		else if (format[*c] == '\\')
 *		{
 *			(*c)++;
 *			escape(format,  c);
 *		}
 */
	}
}

/**
 * _printf - a customized C library Printf
 * @format: format string
 * @...: variables of any type
 * Description: check the README.md file for a better understanding
 *
 * Return: the number of bytes sucessfully outputted
 */
int _printf(const char *format, ...)
{
	va_list list;
	unsigned long int c, tot_print, var_print, len;
	char *buffer;

	if (format == NULL)
		return (-1);
	len = validate_input(format);
	if (len == 0)
		return (0);
	c = tot_print = var_print = 0;
	va_start(list, format);

	buffer = malloc(sizeof(char) * len);

	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}

	main_loop(format, &c, buffer, &var_print, &tot_print, &list);

	free(buffer);
	va_end(list);

	return (tot_print + var_print);
}

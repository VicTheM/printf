#include "main.h"
#include <stdlib>
#include <stdarg.h>

/**
 * _printf - a customized C library Printf
 * @format: format string
 * @...: variables of any type
 *
 * Return: the number of bytes sucessfully outputted
 */

int _printf(*format, ...)
{
	va_list list;
	unsigned int c, tot_print, var_print, nul, start;
	char *buffer;

	nul = start = len = c = tot_print = var_print = 0;
	va_start(list, format);
	buffer = malloc(sizeof(char) * validate_input(format));
	if (buffer == NULL || buffer  == 0)
	{
		free(buffer);
		return (0);
	}
	buffer[nul] = '\0';
	while (format[c] != '\0')
	{
		if (!(format[c] == '%' || format[c] == '\\'))
		{
			nul += fill_buffer(buffer, start, format, &c);
			tot_print += print_buffer((buffer + start));
			start = nul;
		}
		if ((format[c] == '%' && format[c + 1] == '%') ||
				(format[c] == '\\' && format[c + 1] == '\\'))
		{
			tot_print += print_special(format[c + 1]);
			c += 2;
		}
		else if (format[c] == '%')
		{
			c++;
			var_print += specify(format, &c, &list);
		}
		else if (format[c] == '\\')
		{
			c++;
			escape(format,  &c);
		}
	}
	cleanup(&buffer, &list);
	return (tot_print + var_print);

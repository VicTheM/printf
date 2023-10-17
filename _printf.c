#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Entry Point
 * @format: format string
 * @...: variable arguments of variable types
 *
 * Return: Total number of item printed to STDOUT
 */
int _printf(const char *format, ...)
{
	unsigned int total_print, var_print, end, c, k, j, increment, len;
	char spec_char, *spec_ptr, *buffer;
	int spec_int; 
	va_list var;
	spec_t specifiers[] = {
		{'c', print_char},
	       	{'s', print_string},
		{'i', print_string},
	};
	/*
	spec_i converters[] = {
		{'c', do_nothing},
		{'s', do_nothing},
		{'i', conv_int},
	};
	*/
	/* array of pointer to funcs that receives char and return int */

	if (format == NULL)
		return (0);

	va_start(var, format);
	total_print = var_print = increment = end = c = 0;
	len = get_len(format);

	buffer = malloc(sizeof(char)*(len + 1));
	buffer[0] = '\0';

	/* MAIN LOOP */
	while (format[c] != '\0')
	{
		if (format[c] == '%')
		{
			if (format[c + 1] == '%')
			{
				total_print += print_buffer(buffer, total_print, end);
				var_print += print_percent("%");
			}
			else
			{
				k = 1;
				while (k < 5)
				{
					for (j = 0; j < 3; j++) /* len(specifiers) = 2 */
					{
						if (format[c + k] == specifiers[j].a)
						{
							k = 10;
							break;
						}
					}
				}
				switch (specifiers[j].a)
				{
					case 'c':
						spec_char = (char)va_arg(var, int);
						var_print += specify(specifiers[j].ptr, &spec_char, buffer, &total_print, end);
						break;
					case 's':
						spec_ptr = va_arg(var, char *);
						var_print += specify(specifiers[j].ptr, spec_ptr, buffer, &total_print, end);
						break;
					case 'i':
						spec_int = va_arg(var, int);
						spec_ptr = conv_int(&spec_int);
						var_print += specify(specifiers[j].ptr, spec_ptr, buffer, &total_print, end);
						break;
					default:
						return (0);
				}
			}
			increment = 1;
			c += increment;
		}
		/*
		else if (format[c] == '\\')
		{
			escape();
		}*/
		else
		{
			buffer[end] = format[c];
			end++;
		}
		c++;
	}

	if (total_print != end)
	{
		total_print += print_buffer(buffer, total_print, end);
	}

	free(buffer);

	return (total_print + var_print);
}

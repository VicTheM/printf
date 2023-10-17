#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * specify - evaluates a format specifier
 * @special_ptr - pointer to function that receivs special and prints argument
 */
unsigned int specify(int (*ptr)(char *), char *spec, char *buffer, unsigned int *start, unsigned int end)
{
	*start += print_buffer(buffer, *start, end);

	return (ptr(spec));
}

/**
 * get_len - a specialized strlen() function
 * @str: string buffer
 *
 * Return: len excluding special characters
 */
unsigned int get_len(const char *str)
{
	unsigned int len, c;

	len = c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == '%' || str[c] == '\\')
		{
			c += 2;
		}
		else
		{
			len++;
			c++;
		}
	}
	
	return (len);
}

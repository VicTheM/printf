#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a char to STDOUT
 * @a: address of character to be printed
 *
 * Return: 1 on success -1 on failure
 */
long int print_char(char a)
{
	return (write(1, &a, 1));
}


/**
 * print_string - prints a string
 * @str: pointer to str buffer
 *
 * Return: number of characters printed
 */
long int print_string(char *str)
{
	unsigned int k, j, c;
	unsigned long int len;

	len = k = j = c = 0;
	while (str[len] != '\0')
	{
		len++;
		j++;
		if (j == 1024)
		{
			write(1, str + c, 1024);
			c += 1024;
			k++;
			j = 0;
		}
	}
	return (write(1, str, len) + (k * 1024));
}


/**
 * print_buffer - prints a buffer holding characters
 * @buffer: buffer with sufficient space
 *
 * Return: the number of chars printed
 */
long int print_buffer(char *buffer)
{
	unsigned long int len, k, j, c;

	len = c = k = j = 0;
	while (buffer[len] != '\0')
	{
		j++;
		len++;
		if (j == 1024)
		{
			write(1, buffer + c, 1024);
			c += 1024;
			k++;
			j = 0;
		}
	}
	return (write(1, buffer, len) + (k * 1024));
}

/**
 * fill_buffer - same as strcpy(b, f)
 * @b: dest (buffer)
 * @s: start byte in @b
 * @f: src
 * @c: @f index
 *
 * Return: number of bytes transfered to buffer
 */
long int fill_buffer(char *b, unsigned long int s, const char *f,
		unsigned long int *c)
{
	while ((f[*c] != '\0' && !(f[*c] == '%' || f[*c] == '\\')))
	{
		b[s] = f[*c];
		s++;
		(*c)++;
	}
	b[s] = '\0';
	return (s);
}

/**
 * print_special - prints a single special char
 * @a: special charcter
 *
 * Return: 1
 */
long int print_special(char a)
{
	return (write(1, &a, 1));
}

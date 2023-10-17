#include <unistd.h>
#include "main.h"

/**
 * THIS FILE CONTAINS FUNCTIONS THAT HANDLES THE
 * CONVERSION SPECIFIERS
 */


/**
 * print_char - prints a char to STDOUT
 * @a: address of character to be printed
 *
 * Return: 1 on success -1 on failure
 */
int print_char(char *a)
{
	return (write(1, a, 1));
}


/**
 * print_string - prints a string
 * @str - pointer to str buffer
 *
 * Return: number of characters printed
 */
int print_string(char *str)
{
/* later I will modify this to handle str of len > unsigned int */
	unsigned int len;

	len = 0;
	while(*(str + len))
		len++;
	return (write(1, str, len));
}


/**
 * print_percent - jumps the % specifier
 * @a: a = "%"
 *
 * Return: 1 on Success
 */
int print_percent(char *a)
{
	return(write(1, a, 1));
}


/**
 * print_buffer - prints a buffer holding characters
 * @buffer: buffer with sufficient space
 * @start: start byte (inclusive)
 * @end: end byte (exlusive) this byte is set to '\0'
 *
 * Return: the number of chars printed
 */
unsigned int print_buffer(char *buffer, unsigned int start, unsigned int end)
{
	buffer[end] = '\0';
	return (write(1, (buffer + start), (end - start)));
}

#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_number - Prints an integer.
 * @n: The integer
 *
 */

char *conv_int(int *n)
{
	unsigned int t, i, p;
	int c, m;
	char *buf;

	m = t = 1;
	i = p = c = 0;
	buf = malloc(sizeof(char) * 25);
	if (*n == 0)
	{
		buf[c] = '0';
		return (buf);
	}
	/* by max digit in int */
	if (*n < 0)
	{
		buf[c] = '-';
		c++;
		*n *= -1;
	}
	while (1)
	{
		if (*n / m != 0)
		{
			m *= 10;
			p++;
		}
		else
		{
			break;
		}
	}
	while (p > 0)
	{
		t = 1;
		i = 1;
		while (i <  p)
		{
			i++;
			t *= 10;
		}
		buf[c] = ((*n / t) % 10 + '0');
		c++;
		p--;
	}
	return(buf);
}

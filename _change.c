#include "shell.h"

/**
 * _change - converts a string to an integer
 * @s: string to be converted to an integer
 *
 * Return: ni0 (converted integer)
 */
int _change(char *s)
{
	int d, min, isi;
	unsigned int nio;

	d = 0;
	nio = 0;
	min = 1;
	isi = 0;
	while (s[d])
	{
		if (s[d] == '-')
		{
			min *= -1;
		}
		while (s[d] >= '0' && s[d] <= '9')
		{
			isi = 1;
			nio = (nio * 10) + (s[d] - '0');
			d++;
		}
		if (isi == 1)
		{
			break;
		}
		d++;
	}
	nio *= min;
	return (ni);
}
/* change the course */

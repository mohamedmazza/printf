#include "main.h"

/*
 * print char - prints char
 * @types: liste of arguments
 * @buffer: buffer array to handles print
 * @flags; calcuke active flag
 * @width : width
 * @precesion : precision specification
 * @size; number of chars printe
  */
int print_char(va_list types, char buffer[], int flag,
		int width, int precision, int size)
{
	char k = va_arg(types, int);

	return (handle_write_char(k, buffer, flag, width, precision, size));
}
/*
 * print_string - prints a string
 * @types: list a of argument
 * @buffer : buffer array to handle print
 * @flags; calcuke active flag
 * @width : width
 * @precesion : precision specification
 * @size; number of chars printe
 */
int print_string(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char*);

	UNUSED(buffer);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(flags);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = " ";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length, i > 0; i--;)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}

/*
 * print_percent - prints a percent sign
 * @types: lista of arguments
 * @buffer: buffur array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*
 * print_int - prints int
 * @types: lista of arguments
 * @buffer: buffur array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i;

	i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int numbr;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	numbr = (unsigned long int)n;

	if (n < 0)
	{
		numbr = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (numbr > 0)
	{
		buffer[i--] = (numbr % 10) + '0';
		numbr /= 10;
	}
	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/*
 * print_binary - prints  binary
 * @types: lista of arguments
 * @buffer: buffur array to handle print
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: Number of chars printed
 */
int print_binary(va_list types, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int e, s, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	e = va_arg(types, unsigned int);
	s = 2147483648; /* (2 ^ 31) */
	a[0] = e / s;
	for (i = 1; i < 32; i++)
	{
		s /= 2;
		a[i] = (e / s) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char j = '0' + a[i];

			write(1, &j, 1);
			count++;
		}
	}
	return (count);
}

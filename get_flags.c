#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: formatted string to print argument
 * @i: take parameter
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int e, cur_i;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (e = 0; FLAGS_CH[e] != '\0'; e++)
			if (format[cur_i] == FLAGS_CH[e])
			{
				flag |= FLAGS_ARR[e];
				break;
			}
		if (FLAGS_CH[e] == 0)
			break;
	}
		*i = cur_i - 1;

		return (flag);
}

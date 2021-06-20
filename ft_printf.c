#include "libftprintf.h"

int	ft_printf(const char *input, ...)
{
	va_list	arg;
	t_list	flags;

	flags.len = 0;
	flags.i = 0;
	va_start(arg, input);
	while (input[flags.i] != '\0')
	{
		if (input[flags.i] == '%' && input[flags.i + 1])
		{
			if (proverka_na_symbol(input[flags.i + 1]))
				return (flags.len + 1);
			print_dop_func_1(&flags, input, arg);
			if (specificator(&flags, arg, input) == -1)
				return (-1);
		}
		else
		{
			print_dop_func_2(&flags, input);
			ft_putchar(&flags, input[flags.i]);
		}
		flags.i++;
	}
	va_end(arg);
	return (flags.len);
}

#include "libftprintf.h"

void	flagsinitial(t_list *flags)
{
	flags->width = 0;
	flags->point = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->accuracy = -1;
	flags->delitel = 10;
	flags->type = '^';
}

int	proverka_na_symbol(char s)
{
	if ((s > 8 && s < 14))
		return (1);
	return (0);
}

void	checker(t_list *flags, const char *input, va_list arg)
{
	flagsinitial(flags);
	prohod_po_stroke(input, flags, arg);
}

void	print_dop_func_1(t_list *flags, const char *input, va_list arg)
{
	flags->i++;
	checker(flags, input, arg);
}

int	print_dop_func_2(t_list *flags, const char *input)
{
	if (input[flags->i] == '%' && !input[flags->i + 1])
		return (flags->len);
	return (0);
}

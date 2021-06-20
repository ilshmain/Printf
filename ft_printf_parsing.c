#include "libftprintf.h"

int	specificator(t_list *flags, va_list arg, const char *input)
{
	if (input[flags->i] == 's')
		s_specificator(flags, va_arg(arg, char *));
	else if (input[flags->i] == 'c')
		c_specificator(flags, va_arg(arg, int));
	else if (input[flags->i] == '%')
		c_specificator(flags, '%');
	else if (input[flags->i] == 'd' || (input[flags->i]) == 'i')
		d_and_i_specificator(flags, va_arg(arg, int));
	else if (input[flags->i] == 'u' || input[flags->i] == 'x' || \
	input[flags->i] == 'X')
		first_func_D(flags, va_arg(arg, long));
	else if (input[flags->i] == 'p')
		pointer(flags, va_arg(arg, unsigned long));
	else
		return (-1);
	return (0);
}

void	proverkaflaga(const char *input, t_list *flags)
{
	while (1)
	{
		if (input[flags->i] == '-')
			flags->minus = 1;
		else if (input[flags->i] == '0')
			flags->zero = 1;
		else if (input[flags->i] == ' ')
			ft_putchar(flags, ' ');
		else
			break ;
		flags->i++;
	}
}

void	proverka_na_shirinu(const char *input, t_list *flags, va_list arg)
{
	if (input[flags->i] == '*')
	{
		flags->width = va_arg(arg, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width = -flags->width;
		}
		flags->i++;
		return ;
	}
	while (ft_isdigit(input[flags->i]))
	{
		flags->width = flags->width * 10 + (input[flags->i] - '0');
		flags->i++;
	}
}

void	proverka_na_accuracy(const char *input, t_list *flags, va_list arg)
{
	if (input[flags->i] == '.')
	{
		flags->point = 1;
		flags->i++;
		if (flags->point == 1 && proverka_dly_point(flags, input))
		{
			flags->accuracy = 0;
			return ;
		}
	}
	else
		return ;
	if (input[flags->i] == '*' || ft_isdigit_accuracy(input[flags->i]))
		dop_func_pars(input, flags, arg);
	else
	{
		flags->accuracy = 0;
		while (ft_isdigit(input[flags->i]))
		{
			flags->accuracy = flags->accuracy * 10 + (input[flags->i] - '0');
			flags->i++;
		}
	}
}

void	prohod_po_stroke(const char *input, t_list *flags, va_list arg)
{
	proverkaflaga(input, flags);
	proverka_na_shirinu(input, flags, arg);
	proverka_na_accuracy(input, flags, arg);
	proverka_dly_point(flags, input);
}

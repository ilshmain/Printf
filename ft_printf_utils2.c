#include "libftprintf.h"

char	perevod_v_char(int digit, t_list *flags)
{
	char	c;

	if (digit > 9)
	{
		if (flags->type == 'X')
			c = digit + 7 + '0';
		else
			c = digit + 39 + '0';
	}
	else
		c = digit + '0';
	return (c);
}

void	ft_conv(char *out, unsigned long per, unsigned int schet, t_list *flags)
{
	int	digit;

	digit = per % flags->delitel;
	out[--schet] = perevod_v_char(digit, flags);
	per = per / flags->delitel;
	while (per > 0)
	{
		digit = per % flags->delitel;
		out[--schet] = perevod_v_char(digit, flags);
		per = per / flags->delitel;
	}
}

unsigned int	ft_podchet(unsigned long per, int znak, t_list *flags)
{
	unsigned int	schet;

	schet = 0;
	if (per == 0)
		return (1);
	while (per > 0)
	{
		per = per / flags->delitel;
		schet++;
	}
	return (schet + znak);
}

char	*ft_itoa(unsigned long n, t_list *flags)
{
	int				znak;
	unsigned int	schet;
	char			*out;

	znak = 0;
	if (n < 0)
	{
		n = -n;
		znak = 1;
	}
	schet = ft_podchet(n, znak, flags);
	out = (char *)malloc(schet + 1);
	if (!out)
		return (NULL);
	if (znak == 1)
		out[0] = '-';
	out[schet] = '\0';
	ft_conv(out, n, schet, flags);
	return (out);
}

void	dop_func_pars(const char *input, t_list *flags, va_list arg)
{
	if (input[flags->i] == '*')
	{
		flags->accuracy = va_arg(arg, int);
		flags->i++;
		return ;
	}
	if (ft_isdigit_accuracy(input[flags->i]))
	{
		flags->i++;
		while (ft_isdigit(input[flags->i]))
		{
			flags->i++;
			flags->accuracy = 0 * 10 + (input[flags->i] - '0');
		}
		flags->accuracy = flags->accuracy * (-1);
	}
}

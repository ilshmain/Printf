#include "libftprintf.h"

void	putchar_zero(t_list *flags, int i)
{
	while (i-- > 0)
		ft_putchar(flags, '0');
}

void	digits_dop_func(t_list *flags, int i)
{
	if (flags->accuracy > -1)
		flags->zero = 0;
	if (flags->accuracy <= i)
		flags->accuracy = i;
}

void	first_func_D(t_list *flags, unsigned int c)
{
	char	*str;
	int		i;

	if (flags->accuracy > -1)
		flags->zero = 0;
	if (flags->type == 'x' || flags->type == 'X')
		flags->delitel = 16;
	if (c == 0 && flags->accuracy == 0)
	{
		if (flags->zero)
			flags->zero = 0;
		pechat_0_or_probel(flags, flags->width);
		return ;
	}
	str = ft_itoa(c, flags);
	i = ft_strlen(str);
	if (flags->accuracy <= i)
		flags->accuracy = i;
	if (!flags->minus)
		pechat_0_or_probel(flags, flags->width - flags->accuracy);
	putchar_zero(flags, flags->accuracy - i);
	pechat_zhach(str, flags);
	if (flags->minus)
		pechat_0_or_probel(flags, flags->width - flags->accuracy);
	free(str);
}

void	d_and_i_specificator(t_list *flags, long long c)
{
	char	*str;
	int		i;

	if (c >= 0)
		first_func_D(flags, c);
	else
	{
		c = -c;
		str = ft_itoa(c, flags);
		i = ft_strlen(str);
		digits_dop_func(flags, i);
		if (flags->zero)
			ft_putchar(flags, '-');
		if (!flags->minus)
			pechat_0_or_probel(flags, flags->width - flags->accuracy - 1);
		if (!flags->zero)
			ft_putchar(flags, '-');
		putchar_zero(flags, flags->accuracy - i);
		pechat_zhach(str, flags);
		if (flags->minus)
			pechat_0_or_probel(flags, flags->width - flags->accuracy - 1);
		free(str);
	}
}

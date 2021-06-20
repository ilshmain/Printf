#include "libftprintf.h"

void	pointer_shirina(t_list *flags, int i, char *str)
{
	if (!flags->zero)
	{
		pechat_0_or_probel(flags, flags->width - i - 2);
		realization_two_function(flags, str, i);
	}
	else
	{
		pishi_0x(flags);
		pechat_0_or_probel(flags, flags->width - i - 2);
		pechat_zhach(str, flags);
	}
}

void	point_ne_nol(t_list *flags, char *str, int i)
{
	if (flags->accuracy <= i && flags->width <= i)
		realization_two_function(flags, str, i);
	if (flags->accuracy >= i)
	{
		if (flags->width <= flags->accuracy)
		{
			flags->zero = 1;
			flags->minus = 0;
			pishi_0x(flags);
			pechat_0_or_probel(flags, flags->accuracy - i);
			pechat_stroki(flags, str, i);
		}
		else
		{
			pointer_func_3(flags, str, i);
			pointer_func_4(flags, str, i);
		}
	}
	if (flags->accuracy < i && flags->width > i)
	{
		pechat_0_or_probel(flags, flags->width - i - 2);
		realization_two_function(flags, str, i);
	}
}

void	pointer(t_list *flags, unsigned long p)
{
	char	*str;
	int		i;

	flags->delitel = 16;
	str = ft_itoa(p, flags);
	i = ft_strlen(str);
	if (p == 0)
	{
		if (pointer_func_1(flags))
			return ;
	}
	if (flags->point == 0)
		pointer_func_2(flags, str, i);
	else if (flags->point)
		point_ne_nol(flags, str, i);
	free(str);
}

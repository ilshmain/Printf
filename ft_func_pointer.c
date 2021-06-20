#include "libftprintf.h"

int	pointer_func_1(t_list *flags)
{
	if (flags->accuracy == 0)
	{
		if (!flags->minus)
		{
			pechat_0_or_probel(flags, flags->width - 2);
			pishi_0x(flags);
		}
		else
		{
			pishi_0x(flags);
			pechat_0_or_probel(flags, flags->width - 2);
		}
		return (1);
	}
	return (0);
}

void	pointer_func_2(t_list *flags, char *str, int i)
{
	if (flags->width == 0)
		realization_two_function(flags, str, i);
	else if (flags->width > 0 )
	{
		if (!flags->minus)
		{
			if (flags->width > i)
				pointer_shirina(flags, i, str);
			else
				realization_two_function(flags, str, i);
		}
		else
		{
			realization_two_function(flags, str, i);
			pechat_0_or_probel(flags, flags->width - i - 2);
		}
	}
}

void	pointer_func_3(t_list *flags, char *str, int i)
{
	if (flags->minus)
	{
		if (flags->accuracy <= i)
		{
			realization_two_function(flags, str, i);
			pechat_0_or_probel(flags, flags->width - flags->accuracy - 2);
		}
		else
		{
			flags->minus = 0;
			flags->zero = 1;
			pishi_0x(flags);
			pechat_0_or_probel(flags, flags->width - i - \
			(flags->width - flags->accuracy));
			pechat_stroki(flags, str, i);
			flags->minus = 1;
			pechat_0_or_probel(flags, flags->width - i - 2 - \
			(flags->width - i - 2));
		}
	}
}

void	pointer_func_4(t_list *flags, char *str, int i)
{
	if (!flags->minus)
	{
		pechat_0_or_probel(flags, flags->width - flags->accuracy - 2);
		pishi_0x(flags);
		flags->zero = 1;
		pechat_0_or_probel(flags, flags->width - \
		(flags->width - flags->accuracy) - i);
		pechat_stroki(flags, str, i);
	}
}

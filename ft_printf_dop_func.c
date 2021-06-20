#include "libftprintf.h"

void	pishi_0x(t_list *flags)
{
	ft_putchar(flags, '0');
	ft_putchar(flags, 'x');
}

void	pechat_stroki(t_list *flags, char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_putchar(flags, *(str + i));
		i++;
	}
}

void	realization_two_function(t_list *flags, char *str, int i)
{
	pishi_0x(flags);
	pechat_stroki(flags, str, i);
}

#include "libftprintf.h"

void	pechat_0_or_probel(t_list *flags, int n)
{
	if (n <= 0)
		return ;
	while (n > 0)
	{
		if (!flags->minus && flags->zero)
			ft_putchar (flags, '0');
		else
			ft_putchar (flags, ' ');
		n--;
	}
}

void	pechat_zhach(char *str, t_list *flags)
{
	int	len;

	len = 0;
	if (!str)
		return ;
	if (flags->accuracy <= -1)
		len = ft_strlen(str);
	else
		len = flags->accuracy;
	while (*str && len > 0)
	{
		ft_putchar(flags, *str);
		str++;
		len--;
	}
}

void	s_specificator(t_list *flags, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (!(flags->accuracy < 0) && flags->accuracy < len && flags->point == 1)
		len = flags->accuracy;
	if (flags->minus == 1)
	{
		pechat_zhach(str, flags);
		pechat_0_or_probel(flags, flags->width - len);
	}
	else
	{
		pechat_0_or_probel(flags, flags->width - len);
		pechat_zhach(str, flags);
	}
}

void	c_specificator(t_list *flags, char c)
{
	if (flags->minus == 1)
	{
		ft_putchar(flags, c);
		pechat_0_or_probel(flags, flags->width - 1);
	}
	else
	{
		pechat_0_or_probel(flags, flags->width - 1);
		ft_putchar(flags, c);
	}
}

#include "libftprintf.h"

void	ft_putchar(t_list *flags, char c)
{
	write (1, &c, 1);
	flags->len++;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isdigit_accuracy(int c)
{
	return (c == '-');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	proverka_dly_point(t_list *flags, const char *input)
{
	if (input[flags->i] == 'c' || input[flags->i] == 's' || input[flags->i] == 'p' || input[flags->i] == 'd' || \
	input[flags->i] == 'i' || input[flags->i] == 'u' || input[flags->i] == 'x' || input[flags->i] == 'X' || \
	input[flags->i] == '%')
	{
		flags->type = input[flags->i];
		return (1);
	}
	return (0);
}

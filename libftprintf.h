#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	int		width;
	int		len;
	int		point;
	int		zero;
	int		minus;
	int		accuracy;
	int		i;
	int		delitel;
	char	type;
}	t_list;

int		ft_printf(const char *input, ...);
void	checker(t_list *flags, const char *input, va_list arg);
void	flagsinitial(t_list *flags);
void	prohod_po_stroke(const char *input, t_list *flags, va_list arg);
void	ft_putchar(t_list *flags, char c);
int		ft_isdigit(int c);
int		ft_isdigit_accuracy(int c);
int		specificator(t_list *flags, va_list arg, const char *input);
void	s_specificator(t_list *flags, char *str);
void	c_specificator(t_list *flags, char c);
size_t	ft_strlen(const char *s);
void	proverkaflaga(const char *input, t_list *flags);
void	proverka_na_shirinu(const char *input, t_list *flags, va_list arg);
void	proverka_na_accuracy(const char *input, t_list *flags, va_list arg);
void	pechat_0_or_probel(t_list *flags, int n);
void	pechat_zhach(char *str, t_list *flags);
int		proverka_dly_point(t_list *flags, const char *input);
void	d_and_i_specificator(t_list *flags, long long c);
void	first_func_D(t_list *flags, unsigned int c);
void	putchar_zero(t_list *flags, int i);
char	*ft_itoa(unsigned long n, t_list *flags);
void	pointer(t_list *flags, unsigned long p);
void	pishi_0x(t_list *flags);
void	pointer_shirina(t_list *flags, int i, char *str);
void	realization_two_function(t_list *flags, char *str, int i);
void	point_ne_nol(t_list *flags, char *str, int i);
void	pechat_stroki(t_list *flags, char *str, int len);
int		pointer_func_1(t_list *flags);
void	pointer_func_2(t_list *flags, char *str, int i);
void	pointer_func_3(t_list *flags, char *str, int i);
void	pointer_func_4(t_list *flags, char *str, int i);
void	dop_func_pars(const char *input, t_list *flags, va_list arg);
void	print_dop_func_1(t_list *flags, const char *input, va_list arg);
int		print_dop_func_2(t_list *flags, const char *input);
int		proverka_na_symbol(char s);

#endif
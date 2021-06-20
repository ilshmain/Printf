NAME = 	libftprintf.a

SRCS =	ft_printf.c 			ft_printf_parsing.c 		ft_printf_utils1.c 		ft_specificator.c      ft_digits.c      ft_printf_utils2.c     ft_pointer.c \
		ft_func_pointer.c       ft_printf_dop_func.c        ft_printf_dop.c
		
HEADER = libftprintf.h

OBJS = $(patsubst %.c, %.o, $(SRCS))

FLAGS  = -Wall -Wextra -Werror

ARCS = ar rcs

RM	= rm -f

all : $(NAME)

$(NAME)	: $(OBJS)
	$(ARCS)	$(NAME)	$?

bonus :
	@make OBJS="$(OBJS_1)" all

%.o : %.c $(HEADER)
	gcc -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_1)

fclean : clean
	$(RM) $(NAME)

re : fclean all
	
.PHONY : all bonus clean fclean re 

NAME	=	philo

SRCS	=	main.c \
			srcs/utils.c \
			srcs/free.c srcs/init.c \
 			srcs/actions.c \
			srcs/routines.c \
			srcs/print.c \
			srcs/threads.c \
			srcs/utils2.c \
			srcs/checker.c

OBJS	=	$(SRCS:.c=.o)

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Iincludes/

RM	=	rm -f

.c.o:
		@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all	:
		@make $(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) -o $(NAME) $(OBJS)

clean	:
			@$(RM) $(OBJS)

fclean	:	clean
			@$(RM) $(NAME) libft.a

re	:	fclean all

.PHONY:	all clean fclean re

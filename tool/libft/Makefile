HEAD = libft.h

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	   ft_isdigit.c ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c\
	   ft_strlen.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
	   ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
	   ft_memchr.c ft_memcmp.c ft_calloc.c ft_substr.c ft_strjoin.c\
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c\
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		 ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

B_OBJS = ${B_SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all : ${NAME}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${HEAD}

${NAME} : ${OBJS}
	ar -rc ${NAME} $^
	rm -f bonus
	touch all

bonus : ${B_OBJS}
	ar -rc ${NAME} $^
	rm -f all
	touch bonus

clean :
	rm -f ${OBJS} ${B_OBJS} all bonus

fclean : clean
	rm -f ${NAME}

re :
	${MAKE} fclean
	${MAKE} all

.PHONY : clean fclean re

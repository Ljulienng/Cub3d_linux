# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julienngy <julienngy@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 14:56:19 by jnguyen           #+#    #+#              #
#    Updated: 2020/01/29 13:11:59 by julienngy        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_PATH = ./ft_printf/
LIBFT_PATH = ./srcs/
CC = gcc
NAME = libft.a
HEADERS = includes
CFLAGS = -Wall -Wextra -Werror -I $(HEADERS)

PRINTF_SRCS =	pf_c.c \
				pf_s.c \
				pf_id.c \
				pf_u.c \
				pf_x.c \
				pf_p.c \
				ft_flag1.c \
				ft_init.c\
				ft_printf.c \
				buffer.c  \
				ft_converters.c \
				ft_width.c \
				ft_precision.c

SRCS = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strdel.c \
	ft_strnew.c \
	ft_strnjoin.c \
	ft_strcpy.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	get_next_line.c

BMP =	./bmp/encode.c ./bmp/bitmap.c ./bmp/check.c ./bmp/header.c \
		./bmp/rgb_encode.c ./bmp/utils.c

PRINTF_FILES = $(addprefix $(PRINTF_PATH), $(PRINTF_SRCS))
LIBFT_FILES = $(addprefix $(LIBFT_PATH), $(SRCS))


OBJ = $(LIBFT_FILES:.c=.o)
OBJ_PRINTF = $(PRINTF_FILES:.c=.o)
OBJ_BMP = $(BMP:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_PRINTF) $(OBJ_BMP)
			ar rc $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_BMP)
			ranlib $(NAME)

clean:
			rm -f $(OBJ) $(OBJ_PRINTF) $(OBJ_BMP)
fclean:	clean
			rm -f $(NAME)

re:		fclean all

.PHONY : all clean fclean re

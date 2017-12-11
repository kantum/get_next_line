# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svigouro <svigouro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 10:47:22 by svigouro          #+#    #+#              #
#    Updated: 2017/06/07 10:47:33 by svigouro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
.SUFFIXES:

NAME    = 	libft.a

SRC_DIR = 	./srcs
IN_DIR  = 	./includes

RAW_SRC = 	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_sqrt.c \
			ft_factorial.c \
			ft_power.c \
			ft_swap.c

OBJ     = 	$(RAW_SRC:.c=.o)
SRC 	= 	$(addprefix $(SRC_DIR)/,$(RAW_SRC))

CC      = 	gcc
CFLAGS  = 	-Wall -Wextra -Werror
AR      = 	ar
ARFLAGS = 	rc

GREY    = 	$'\x1b[30m
RED     = 	$'\x1b[31m
GREEN   = 	$'\x1b[32m
YELLOW  = 	$'\x1b[33m
BLUE    = 	$'\x1b[34m
PURPLE  = 	$'\x1b[35m
CYAN    = 	$'\x1b[36m
WHITE   = 	$'\x1b[37m
BOLD    = 	$'\x1b[1m
UNDER   = 	$'\x1b[4m
REV     = 	$'\x1b[7m
END     = 	$'\x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "${GREEN}➤  ${BOLD}$(AR) $(ARFLAGS) $(NAME) $(OBJ)${END}"
	@echo "${GREEN}➤  ${BOLD}ranlib $(NAME)${END}"

$(OBJ):
	@$(CC) $(CFLAGS) -I $(IN_DIR) -c $(SRC)
	@echo "${GREEN}[  Compiling $(NAME)  ]${END}"
	@echo "${GREEN}➤  ${BOLD}$(CC) $(CFLAGS) -I $(IN_DIR) -c $(SRC)${END}"

clean:
	@rm -f $(OBJ)
	@echo "${RED}[  Cleaning $(NAME)  ]${END}"
	@echo "${RED}➤  ${BOLD}rm -f $(OBJ)${END}"

fclean: clean
	@echo "${RED}➤  ${BOLD}rm -f $(NAME)${END}"
	@rm -f $(NAME)

re: fclean all

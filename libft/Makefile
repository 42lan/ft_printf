# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2019/04/17 17:43:42 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= libft.a

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
CC			= /usr/bin/clang
RM			= /bin/rm -rf
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p

# **************************************************************************** #
# Directories of source and object files

INCDIR		= -I ./include
SRCDIR		= ./sources
OBJDIR		= ./objects

# **************************************************************************** #
# List of source and header files

SRCNAME		= ft_memset.c			\
			  ft_bzero.c			\
			  ft_memcpy.c			\
			  ft_memccpy.c			\
			  ft_memmove.c			\
			  ft_memchr.c			\
			  ft_memcmp.c			\
			  ft_strlen.c			\
			  ft_strdup.c			\
			  ft_strcpy.c			\
			  ft_strncpy.c			\
			  ft_strcat.c			\
			  ft_strncat.c			\
			  ft_strlcat.c			\
			  ft_strchr.c			\
			  ft_strrchr.c			\
			  ft_strstr.c			\
			  ft_strnstr.c			\
			  ft_strcmp.c			\
			  ft_strncmp.c			\
			  ft_atoi.c				\
			  ft_isalpha.c			\
			  ft_isdigit.c			\
			  ft_isalnum.c			\
			  ft_isascii.c			\
			  ft_isprint.c			\
			  ft_toupper.c			\
			  ft_tolower.c			\
			  ft_memalloc.c			\
			  ft_memdel.c			\
			  ft_strnew.c			\
			  ft_strdel.c			\
			  ft_strclr.c			\
			  ft_striter.c			\
			  ft_striteri.c			\
			  ft_strmap.c			\
			  ft_strmapi.c			\
			  ft_strequ.c			\
			  ft_strnequ.c			\
			  ft_strsub.c			\
			  ft_strjoin.c			\
			  ft_strtrim.c			\
			  ft_strsplit.c			\
			  ft_itoa.c				\
			  ft_putchar.c			\
			  ft_putstr.c			\
			  ft_putendl.c			\
			  ft_putnbr.c			\
			  ft_putchar_fd.c		\
			  ft_putstr_fd.c		\
			  ft_putendl_fd.c		\
			  ft_putnbr_fd.c		\
			  ft_lstnew.c			\
			  ft_lstdelone.c		\
			  ft_lstdel.c			\
			  ft_lstadd.c			\
			  ft_lstiter.c			\
			  ft_lstmap.c			\
			  ft_isspace.c			\
			  ft_iswhitespace.c		\
			  ft_nblen.c			\
			  ft_cntwords.c			\
			  ft_isseparator.c		\
			  ft_strnew2d.c			\
			  ft_swap.c				\
			  ft_islower.c			\
			  ft_isupper.c			\
			  ft_sitoa_base.c		\
			  ft_uitoa_base.c

# **************************************************************************** #
# Automatic variables where are listed the names of source and object files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

# **************************************************************************** #
# Rules

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)
	$(CC) $(INCDIR) -o $@ -c $<

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	$(NORMINETTE) $(INCDIR) $(SCR)

.PHONY: all clean fclean re norm

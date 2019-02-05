# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/02/06 00:01:25 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General
NAME		= ft_printf
CPPFLAGS	= -I $(INCDIR)
LIBNAME		= libft.a

# **************************************************************************** #
# System commands
CC			= /usr/bin/clang -Wall -Wextra -Werror
MAKE		= /usr/bin/make -C
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes
LIBDIR		= ./libft

# **************************************************************************** #
# List of source files
SRCNAME		= main.c \
			  ft_printf.c \
			  parsing.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files
SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LIB			= $(addprefix $(LIBDIR)/, $(LIBNAME))

# **************************************************************************** #
# Rules

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(MKDIR) $(OBJDIR)
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	$(MAKE) $(LIBDIR) re

clean:
	$(RM) $(OBJ) $(OBJDIR)
	$(MAKE) $(LIBDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBDIR) fclean

re: fclean all

norm:
	$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)

.PHONY: all clean fclean re norm

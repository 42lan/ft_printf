# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/03/16 20:13:10 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General
NAME		= libftprintf.a
CPPFLAGS	= -I $(INCDIR)
LIBNAME		= libft.a

# **************************************************************************** #
# System commands
CC			= /usr/bin/clang -Wall -Wextra -Werror
AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
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
SRCNAME		= main.c			\
			  ft_printf.c		\
			  parsing.c			\
			  initialization.c	\
			  flags.c			\
			  placeholder.c		\
			  get_int.c			\
			  types.c			\
			  buffer.c			\
			  length.c			\
			  specs.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files
SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))

# **************************************************************************** #
# Rules

# .SILENT:

all: $(NAME) $(LFT)
	$(CC) $(NAME) $(LFT) # Для того, чтобы создать исполняемый файл a.out
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ 62

$(NAME): $(LFT) $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)
	$(CC) $(CPPFLAGS) -o $@ -c $<

$(LFT):
	$(MAKE) $(LIBDIR)

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

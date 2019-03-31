# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/03/31 11:42:22 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General
NAME		= libftprintf.a
CPPFLAGS	= -I $(INCDIR)
LIBNAME		= libft.a

# **************************************************************************** #
# System commands
#
##
###
####
#####
######
#######
########
#########
#CC			= /usr/bin/clang -Wall -Wextra -Werror
#########
########
#######
######
#####
####
###
##
#
CC			= /usr/bin/clang
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
# НУЖНО БУДЕТ УБРАТЬ main.c ИЗ $(SRCNAME)
# НУЖНО БУДЕТ УБРАТЬ main.c ИЗ $(SRCNAME)
# НУЖНО БУДЕТ УБРАТЬ main.c ИЗ $(SRCNAME)
# НУЖНО БУДЕТ УБРАТЬ main.c ИЗ $(SRCNAME)
SRCNAME		= main.c					\
			  ft_printf.c				\
			  parsing.c					\
			  buffer.c					\
			  tools/placeholder.c		\
			  tools/initialization.c	\
			  tools/get_number.c		\
			  specs/set_flags.c			\
			  specs/set_length.c		\
			  specs/set_specs.c			\
			  specs/specs_handler.c		\
			  types/types.c				\
			  types/type_c.c			\
			  types/type_s.c			\
			  types/type_di.c			\
			  types/type_percent.c		\
			  types/unknown.c

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
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ СВЕРХУ
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ СВЕРХУ
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ СВЕРХУ
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ СВЕРХУ
# НЕ ЗАБЫТЬ УБРАТЬ ЛИНИЮ СВЕРХУ

$(NAME): $(LFT) $(OBJ)
	$(AR) $(NAME) $(OBJ) ./libft/*.o
	$(RANLIB) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)/{types,tools,specs}
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

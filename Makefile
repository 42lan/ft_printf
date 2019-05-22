# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/05/22 12:49:25 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= libftprintf.a
LIBNAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR		= ./libft
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes

# **************************************************************************** #
# List of source files

SRCNAME		= ft_printf.c				\
			  parsing.c					\
			  tools/buffer.c			\
			  tools/initialization.c	\
			  tools/get_si.c			\
			  tools/get_ui.c			\
			  tools/get_f.c				\
			  specs/wildcard.c			\
			  specs/set_specs.c			\
			  specs/set_flags.c			\
			  specs/set_length.c		\
			  specs/apply_specs.c		\
			  types/type_b.c			\
			  types/type_c.c			\
			  types/type_d.c			\
			  types/type_f.c			\
			  types/type_o.c			\
			  types/type_p.c			\
			  types/type_s.c			\
			  types/type_u.c			\
			  types/type_x.c			\
			  types/unknown.c			\
			  types/percent.c

# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
LFTOBJ		= $(LIBDIR)/objects/*.o

# **************************************************************************** #
# Extra

CLEAR       = "\033[K"
EOC			= "\033[0;0m"
GREEN		= "\033[0;32m"
CR			= "\r"$(CLEAR)
BASENAME	= `basename $(PWD)`

# **************************************************************************** #
# Rules

.SILENT:

all: $(NAME) $(LFT)

$(NAME): $(LFT) $(OBJ)
	$(AR) $(NAME) $(OBJ) $(LFTOBJ)
	$(RANLIB) $(NAME)
	printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	-@$(MKDIR) $(OBJDIR)/{types,tools,specs}
	$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	printf $(CR)"[ $(BASENAME)/%s ]"$(CLEAR) $@

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
	$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources

.PHONY: all clean fclean re norm

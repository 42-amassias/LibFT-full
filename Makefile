# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Antoine Massias <massias.antoine.pro@gm    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 09:50:29 by amassias          #+#    #+#              #
#    Updated: 2024/05/11 18:14:45 by Antoine Mas      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############################################################################ #
#                                                                              #
# Tools                                                                        #
#                                                                              #
# ############################################################################ #

RM				=	/usr/bin/rm -f
ECHO			=	/usr/bin/echo

# ############################################################################ #
#                                                                              #
# Global variables                                                             #
#                                                                              #
# ############################################################################ #

SRC_DIR			:=	src
INC_DIR			:=	include
OBJ_DIR			:=	build

TARGET			:=	libftfull.a

CC				:=	cc

CFLAGS			:=	-Wall -Werror -Wextra

include Files.mk

# ############################################################################ #
#                                                                              #
# Object generation                                                            #
#                                                                              #
# ############################################################################ #

OBJS	=	$(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))

# ############################################################################ #
#                                                                              #
# Terminal manipulations                                                       #
#                                                                              #
# ############################################################################ #

TERM_RESET			=	\033[0m
TERM_BLACK			=	\033[30m
TERM_RED			=	\033[31m
TERM_GREEN			=	\033[32m
TERM_YELLOW			=	\033[33m
TERM_BLUE			=	\033[34m
TERM_MAGENTA		=	\033[35m
TERM_CYAN			=	\033[36m
TERM_WHITE			=	\033[37m

TERM_UP				=	\033[1A
TERM_CLEAR_LINE		=	\033[2K\r

# ############################################################################ #
#                                                                              #
# Phony rules                                                                  #
#                                                                              #
# ############################################################################ #

.PHONY: all clean fclean re norminette _header _obj_header _obj_footer

all: $(TARGET)

clean:
	@printf "$(TERM_YELLOW)Removing \"%s\"...\n$(TERM_RESET)" $(TARGET)
	@$(RM) -r $(OBJS)

fclean: clean
	@printf "$(TERM_YELLOW)Removing %d objects...\n$(TERM_RESET)" $(words $(OBJS))
	@$(RM) $(TARGET)

re: fclean all

norminette:
	@norminette $(SRC_DIR) $(INC_DIR) | grep -Ev '^Notice|OK!$$'	\
	&& $(ECHO) -e '\033[1;31mNorminette KO!'						\
	|| $(ECHO) -e '\033[1;32mNorminette OK!'						\

_header:
	@printf "$(TERM_GREEN)Welcome to $(TERM_BLUE)\"%s\"$(TERM_GREEN) builder !\n$(TERM_RESET)" $(TARGET)

_obj_header:
	@printf "$(TERM_MAGENTA)Building objects$(TERM_RESET)...\n"

_obj_footer:
	@printf "$(TERM_UP)$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building $(TERM_BLUE)%d$(TERM_GREEN) object(s) !\n$(TERM_RESET)" $(words $(OBJS))

# ############################################################################ #
#                                                                              #
# Binary / Library generation                                                  #
#                                                                              #
# ############################################################################ #

$(TARGET): _header _obj_header $(OBJS) _obj_footer
	@printf "$(TERM_MAGENTA)Making archive $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...$(TERM_RESET)" $@
	@ar -rcs $@ $(OBJS)
	@cp $(INC_DIR)/libft.h .
	@printf "$(TERM_CLEAR_LINE)$(TERM_GREEN)Done building archive $(TERM_BLUE)\"%s\"$(TERM_GREEN) !\n$(TERM_RESET)" $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(TERM_CLEAR_LINE)$(TERM_MAGENTA)Compiling $(TERM_BLUE)\"%s\"$(TERM_MAGENTA)...\n$(TERM_RESET)" $@
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ -I$(INC_DIR) $(CFLAGS)
	@printf "$(TERM_UP)"
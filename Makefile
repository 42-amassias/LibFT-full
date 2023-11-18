# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 09:50:29 by amassias          #+#    #+#              #
#    Updated: 2023/11/18 16:18:50 by amassias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR			:=	sources
INC_DIR			:=	includes

FLAG__INCLUDES	:=							\
	-I$(INC_DIR)/libft
FILES_SROUCES	:=							\
	libft/ft_abs.c							\
	libft/ft_atoi.c							\
	libft/ft_bzero.c						\
	libft/ft_calloc.c						\
	libft/ft_isalnum.c						\
	libft/ft_isalpha.c						\
	libft/ft_isascii.c						\
	libft/ft_isdigit.c						\
	libft/ft_isprint.c						\
	libft/ft_itoa.c							\
	libft/ft_lstadd_back.c					\
	libft/ft_lstadd_front.c					\
	libft/ft_lstclear.c						\
	libft/ft_lstdelone.c					\
	libft/ft_lstiter.c						\
	libft/ft_lstlast.c						\
	libft/ft_lstmap.c						\
	libft/ft_lstnew.c						\
	libft/ft_lstsize.c						\
	libft/ft_max.c							\
	libft/ft_memchr.c						\
	libft/ft_memcmp.c						\
	libft/ft_memcpy.c						\
	libft/ft_memmove.c						\
	libft/ft_memset.c						\
	libft/ft_memswap.c						\
	libft/ft_min.c							\
	libft/ft_putchar_fd.c					\
	libft/ft_putendl_fd.c					\
	libft/ft_putnbr_fd.c					\
	libft/ft_putstr_fd.c					\
	libft/ft_qsort.c						\
	libft/ft_split.c						\
	libft/ft_strchr.c						\
	libft/ft_strdup.c						\
	libft/ft_striteri.c						\
	libft/ft_strjoin.c						\
	libft/ft_strlcat.c						\
	libft/ft_strlcpy.c						\
	libft/ft_strlen.c						\
	libft/ft_strmapi.c						\
	libft/ft_strncmp.c						\
	libft/ft_strnstr.c						\
	libft/ft_strrchr.c						\
	libft/ft_strtrim.c						\
	libft/ft_substr.c						\
	libft/ft_tolower.c						\
	libft/ft_toupper.c						\

DEFINES			:=	

ifdef USE_FTPRINTF
FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\
	-I$(INC_DIR)/ft_printf
FILES_SROUCES	:=	$(FILES_SROUCES)		\
	ft_printf/ft_printf						\
	ft_printf/ft_vprintf					\
	ft_printf/utils							\
	ft_printf/flags/align_sign				\
	ft_printf/flags/force_sign				\
	ft_printf/flags/prefix					\
	ft_printf/flags/left_justify			\
	ft_printf/flags/precision				\
	ft_printf/flags/zero_padding			\
	ft_printf/printers/number				\
	ft_printf/printers/hex					\
	ft_printf/printers/string				\
	ft_printf/specifiers/char				\
	ft_printf/specifiers/string				\
	ft_printf/specifiers/pointer			\
	ft_printf/specifiers/decimal			\
	ft_printf/specifiers/integer			\
	ft_printf/specifiers/unsigned			\
	ft_printf/specifiers/hex_lo				\
	ft_printf/specifiers/hex_up
DEFINES			:=	$(DEFINES)				\
	-DUSE_LIB__FT_PRINTF
endif

ifdef USE_GNL
FLAG__INCLUDES	:=	$(FLAG__INCLUDES)		\

FILES_SROUCES	:=	$(FILES_SROUCES)		\

DEFINES			:=	$(DEFINES)				\
	-DUSE_LIB__GET_NEXT_LINE
endif

OBJS	=	$(addprefix $(SRC_DIR)/,$(addsuffix .o,$(FILES_SROUCES)))

TARGET	:=	libftfull.a

CC		:=	cc

.PHONY: all clean fclean re

all: $(TARGET)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

$(TARGET): $(OBJS)
	ar -rcs $@ $^
	cp includes/libft/libft.h .

%.o: %.c
	$(CC) -c $< -o $@ $(DEFINES) $(FLAG__INCLUDES)
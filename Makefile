# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akant <akant@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/08 10:27:23 by akant         #+#    #+#                  #
#    Updated: 2021/04/08 15:47:34 by akant         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# NAME = miniRT

# SRCS = minirt.c

# OBJS = $(SRCS:%.c=%.o)

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# 	# ar -rcs $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

NAME = minirt
OBJ = minirt.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
# $(NAME):
#   gcc $(FLAGS) -o $(NAME) $(SRCS)
#to update
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all

# SRCS = ft_printf.c convert_char.c convert_hex.c convert_int.c \
# 		convert_percentage.c convert_pointer.c convert_string.c \
# 		convert_unsigned.c itoa.c utils.c

# HEADER_FILES = printf.h
# CFLAGS = -Wall -Wextra -Werror
# OBJS = $(SRCS:%.c=%.o)
# LIBFTLIBRARY = ./libft/libft.a

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(MAKE) -C ./libft
# 	ar -rcs $(NAME) $(OBJS) $(LIBFTLIBRARY)
# 	ar -q $(LIBFTLIBRARY) $(OBJS)
# 	cp $(LIBFTLIBRARY) $(NAME)

# %.o: %.c $(HEADER_FILES)
# 	$(CC) -c $(CFLAGS) -o $@ $<

# clean:
# 	rm -f $(OBJS)
# 	$(MAKE) -C ./libft clean

# fclean: clean
# 	rm -f $(NAME)
# 	$(MAKE) -C ./libft fclean

# re: fclean all

# .PHONY: all clean fclean re

NAME = libftprintf.a
SRCDIR = ./src
SRCS = $(SRCDIR)/ft_printf.c \
		$(SRCDIR)/print_uxX.c \
		$(SRCDIR)/print_csdip.c
OBJSDIR = ./obj
OBJS = $(addprefix $(OBJSDIR)/, $(notdir $(SRCS:.c=.o)))
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
INCLUDES = -I ./“　”　//ヘッダーファイルがあるディレクトリを参照する

$(NAME): $(OBJS)
		make -C ./libft
		cp libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJS)

$(OBJSDIR)/%.o : $(SRCDIR)/%.c　　//ここはこう書く
		mkdir -p ./obj //objファイルを作る
		$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDES)　//作ったファイルの中に入れる

.PHONY : all clean fclean re

all : $(NAME)

clean : 
		make clean -C ./libft
		rm -rf $(NAME) $(OBJS)

fclean : clean
		make fclean -C ./libft
		rm -rf $(NAME)

re : fclean all

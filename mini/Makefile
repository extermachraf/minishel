NAME = minishel
CC = cc
SRC = main_parc.c \
	./src/lexer.c \
	./src/token.c \
	./src/lexer1.c \
	./src/linked_outils.c \
	./src/outils.c \
	./src/parser.c \
	./src/parser1.c \
	./src/get_env.c \
	./src/expand_dollar.c \
	./src/lexer_dollar.c 

FLAGS = -Wall -Wextra -Werror
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC) $(FLA) -lreadline $(SRC) $(ARG) minishel ./libft/libft.a -g

clean : 
	rm -f $(NAME)
	make clean -C ./libft
fclean : clean

re: fclean all
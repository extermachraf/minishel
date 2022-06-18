NAME = minishel
CC = cc
SRC = main_parc.c \
	./src/lexer.c \
	./src/token.c \
	./src/outils.c \

FLAGS = -Wall -Wextra -Werror
ARG = -o

all : $(NAME)

$(NAME): $(SRC)
	make -C ./libft
	$(CC)  $(FLA) -lreadline $(SRC) $(ARG) minishel ./libft/libft.a

clean : 
	rm -f $(NAME)
	make clean -C ./libft
fclean : clean

re: fclean all
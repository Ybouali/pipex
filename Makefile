NAME = pipex

SRC = functions/ft_putendl_fd.c functions/ft_split.c functions/ft_strdup.c \
	  functions/ft_strjoin.c functions/ft_strncmp.c \
	  mandatory/ft_childs.c mandatory/ft_free.c mandatory/pipex.c \

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

HEADER = ./includes/pipex.h

all: $(NAME)

$(NAME): 
	@echo "\033[92mCREATE PIPEX\033[0m"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) 
	@echo "\033[92mPIPEX IS READY\033[0m"

clean:
	@rm -rf *.o
	@echo "\033[92mOBJECT FILES DELETED\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[92mPIPEX IS DELETED\033[0m"

re: fclean all

.PHONY: all clean fclean re
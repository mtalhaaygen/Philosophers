NAME = philo
SRCS = philosophers.c source.c check.c main.c threadfunc.c
OBJ = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g #-lpthread
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : clean fclean all re
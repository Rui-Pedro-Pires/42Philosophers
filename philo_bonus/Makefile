SRC = ./src_bonus/init_bonus.c ./src_bonus/philo_bonus.c \
		./src_bonus/atoi_bonus.c ./src_bonus/rotine_bonus.c \
		./src_bonus/time_utils_bonus.c ./src_bonus/semaphore_utils1_bonus.c\
		./src_bonus/monitoring_bonus.c ./src_bonus/semaphore_utils2_bonus.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -pthread -Wall -Werror -Wextra -fsanitize=thread

CC = cc

RM = rm -f

NAME = philo_bonus

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling objects"
	@echo "Creating program philo_bonus"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
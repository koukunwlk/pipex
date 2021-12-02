NAME 			=	 pipex
INCLUDES		= 	-I ./includes
CC				= 	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror
FILES			= 	pipex.c ft_split.c
SRC				=	$(FILES)
SRC_ALL			=	$(addprefix ./src/, $(FILES))
OBJS			=	$(SRC:%.c=%.o)
RM				=	rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) -o $(NAME)

$(OBJS): $(SRC_ALL)
	$(CC)  -c $(SRC_ALL)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
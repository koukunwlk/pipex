NAME 			=	 pipex
LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a
INCLUDES		= 	-I ./includes
CC				= 	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror
FILES			= 	pipex.c
SRC				=	$(FILES)
SRC_ALL			=	$(addprefix ./src/, $(FILES))
OBJS			=	$(SRC:%.c=%.o)
RM				=	rm -rf


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(INCLUDES) -L $(LIBFT)

$(OBJS): $(SRC_ALL)
	$(CC)  -c $(SRC_ALL)

$(LIBFT):
	$(MAKE) --no-print-directory -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJS)
	$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean
	
fclean: clean
	$(RM) $(NAME)
	$(MAKE) --no-print-directory -C $(LIBFT_PATH) fclean

re: fclean all
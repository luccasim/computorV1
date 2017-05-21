NAME		=	computorV1

# COMPILATION

CC			=	llvm-gcc

# FLAGS

CFLAGS		=	-Wall -Werror -Wextra

# DIRECTORY

DINC		=	includes/
DSRC		=	srcs/
DOBJ		=	objs/

# INCLUDES

INC			=	-I includes -I libft/includes

# LIBRARY

LIB			=	-L libft/ -lft

# SOURCES

SRC			=	$(shell find srcs -name '*.c' -type f)
OBJ			=	$(patsubst %.c, $(DOBJ)%.o, $(SRC))
HEAD		=	$(shell find includes -name '*.h' -type f)

# COMMAND

MKD			=	/bin/mkdir -p
RMD			=	/bin/rm -rf

all: $(NAME) 

$(NAME): $(HEAD) $(OBJ)
	@make -C libft/ > /dev/null 2>&1
	@$(CC) -o $(NAME) $(INC) $(LIB) $(OBJ)

$(DOBJ)%.o: %.c
	@$(MKD) $(DOBJ)/$(DSRC) > /dev/null 2>&1
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	$(RMD) $(DOBJ)

fclean: clean
	$(RMD) $(NAME)

re: fclean all

.PHONY: all clean fclean re
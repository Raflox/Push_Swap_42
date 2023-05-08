################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        	:= gcc
FLAGS    	:= -Wall -Wextra -Werror -fsanitize=address -g
LIBFTA		= ./libft/libft.a

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=            utils/move/rotate.c \
                          utils/move/push.c \
                          utils/move/rev_rotate.c \
                          utils/move/swap.c \
                          utils/get/getters.c \
                          utils/lib/ft_utils.c \
                          utils/lib/free.c \
						  utils/lib/lst_utils.c \
                          utils/check/checkers.c \
                          utils/error/error.c \
						  utils/sort/sort.c \
                          main.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

# ${NAME}:	${OBJS}
# 			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
# 			${CC} ${FLAGS} -o ${NAME} ${OBJS}
# 			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

$(NAME):	$(LIBFTA) $(OBJS)
			$(CC) $(FLAGS) $(LIBFTA) $(OBJS) -o $(NAME)
			@echo "$(GREEN)Successfully built --> $(YELLOW)$(NAME)$(DEFAULT)"

$(LIBFTA):
			make -C libft
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re

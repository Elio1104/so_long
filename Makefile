SHELL	=	/bin/bash

# Variables

NAME		=	so_long
LIBFT		=	lib/libft
MINILIBX	=	lib/minilibx
INC			=	inc
HEADER		=	-I inc
SRC_DIR		=	src/
OBJ_DIR		=	obj/
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f
ECHO		=	echo -e
MINILIBXCC	=	-I mlx -L lib/minilibx -lmlx
OPENGL		=	-framework OpenGL -framework AppKit

# Colors

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

# Sources

SRC_FILES	=	border_check key_hook map_validation so_long window path_checking loop bonus init_struct floor_filling

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

###

start:
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@$(ECHO) -n "$(YELLOW)[MINILIBX]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make -s -C $(MINILIBX)
			@$(ECHO) -n "$(ORANGE)=======$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => 100%$(DEF_COLOR)"
			@$(ECHO) -n "$(YELLOW)[so_long]:\t$(DEF_COLOR)"
			@$(ECHO) -n "$(RED)[$(DEF_COLOR)"
			@make all
			@$(ECHO) -n "$(RED)]$(DEF_COLOR)"
			@$(ECHO) "$(GREEN) => 100%$(DEF_COLOR)"

all:		$(NAME)

$(NAME):	$(OBJ) $(OBJF)
			@$(CC) $(FLAGS) $(OBJ) $(HEADER) libft.a $(MINILIBXCC) $(OPENGL) -o $(NAME)		

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
			@$(ECHO) -n "$(ORANGE)=$(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

clean:
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(LIBFT)
			@make clean -C $(MINILIBX)
			@$(ECHO) -n "$(BLUE)[minilibx]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(BLUE)[so_long]:\tobject files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@$(ECHO) -n "$(CYAN)[LIBFT]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[minilibx]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"
			@$(ECHO) -n "$(CYAN)[so_long]:\texec. files$(DEF_COLOR)$(GREEN)  => Cleaned!$(DEF_COLOR)\n"

re:			fclean start
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!$(DEF_COLOR)\n"

.PHONY:		start all clean fclean re
##
## EPITECH PROJECT, 2017
## Makefile <project>
## File description:
## makefile for <project>
##

SRC_DIR		=	$(realpath ./src)

SRC_ACT_DIR	=	$(realpath ./src/interactions)

SRC_BUT_DIR	=	$(realpath ./src/buttons)

SRC_MAP_DIR	=	$(realpath ./src/map)

SRC_PROMPT_DIR	=	$(realpath ./src/prompt)

SRC_ACT		=	$(SRC_ACT_DIR)/init_interactions.c	\
			$(SRC_ACT_DIR)/interactions.c		\
			$(SRC_ACT_DIR)/keyboard_arrows.c	\
			$(SRC_ACT_DIR)/keyboard_interactions.c	\
			$(SRC_ACT_DIR)/interactions_map.c	\
			$(SRC_ACT_DIR)/keyboard_ctrl.c		\
			$(SRC_ACT_DIR)/keyboard_ctrl2.c

SRC_BUT		=	$(SRC_BUT_DIR)/buttons.c		\
			$(SRC_BUT_DIR)/info.c			\
			$(SRC_BUT_DIR)/map_modif_buttons.c

SRC_MAP		=	$(SRC_MAP_DIR)/map.c			\
			$(SRC_MAP_DIR)/load_map.c		\
			$(SRC_MAP_DIR)/load_3d_map.c		\
			$(SRC_MAP_DIR)/draw_map.c		\
			$(SRC_MAP_DIR)/destroy_map.c		\
			$(SRC_MAP_DIR)/map_create.c		\
			$(SRC_MAP_DIR)/modify_mapsize.c

SRC_PROMPT	=	$(SRC_PROMPT_DIR)/graph_prompt.c	\
			$(SRC_PROMPT_DIR)/input.c		\
			$(SRC_PROMPT_DIR)/snapshot.c

SRC		=	$(SRC_DIR)/main.c	\
			$(SRC_DIR)/parse_arg.c	\
			$(SRC_DIR)/my_world.c	\
			$(SRC_DIR)/game_loop.c	\
			$(SRC_DIR)/my_text.c

OBJ		=	$(SRC:.c=.o)				\
			$(SRC_ACT:.c=.o)			\
			$(SRC_BUT:.c=.o)			\
			$(SRC_MAP:.c=.o)			\
			$(SRC_PROMPT:.c=.o)

CPPFLAGS	+=	-I./include/

LDFLAGS		+=	-Llib -lmy -lc_graph_prog -lm

CFLAGS		+=	-Wextra -Wall -g

NAME		=	my_world

all:			$(NAME)

$(NAME):		$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) -f $(OBJ)

fclean:			clean
		$(RM) -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 20:40:36 by rmalkevy          #+#    #+#              #
#    Updated: 2017/03/30 15:41:53 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = main.c \
      init_structure.c \
      value_of_light.c \
      vector_1.c \
      vector_2.c \
      window.c \
      closest_intersection.c \
      sphere.c \
      plane.c \
      cylinder.c \
      cone.c \
      color.c \
      rotation.c \
      scene_1.c \
      scene_2.c \
      scene_3.c \
      scene_4.c \
      scene_5.c \
      work_with_scene.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Wextra -Werror -g

INC = ./

LIB = -L ./libft/ -lft
LIBMLX = -L ./minilibx/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft/
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LIBMLX) -lmlx -framework OpenGL -framework AppKit -g

%.o: %.c
		$(CC) $(FLGS) -c $<

clean:
		make -C ./libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C ./libft/ fclean
		rm -f $(NAME)

re: fclean all

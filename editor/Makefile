# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 19:17:35 by cmanfred          #+#    #+#              #
#    Updated: 2019/07/13 19:18:14 by cmanfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../maped

FILES = main.c ft_menu.c ft_key.c ft_brazenham.c ft_xpm_read.c ft_net.c ft_buttons_help.c ft_buttons.c\
		ft_save_as.c ft_nodes.c ft_point.c ft_ctrl_z.c ft_node_secondary.c ft_tex.c \
		ft_scroll.c ft_choose_tex.c ft_sdl_operations.c ft_bmp_read.c ft_draw_things.c \
		ft_intersection.c ft_sectors.c ft_point_transformation.c ft_sector_secondary.c \
		ft_fill_sector_info.c ft_sec_menu.c ft_draw_nbr.c ft_change_texture.c \
		ft_player_actions.c ft_save_to_file.c ft_print_to_file.c ft_geometry.c \
		ft_read_from_file.c ft_read_from_file_secondary.c ft_lst_secondary.c

SRC = $(addprefix srcs/, $(FILES))

FILESO = $(addprefix objectives/, $(FILES:.c=.o))

FLAGS = -Wall -Wextra -Werror

HEADERS = -I include -I ../libft/include  -I ../libft/src

LIBA = -L ../libft/src -lft

ADD = -framework OpenGL -framework AppKit

INCL = -I ../libft -I . -I .. \
	   -I ../SDL2/SDL2_mixer.framework/Versions/A/Headers \
	   -I ../SDL2/SDL2.framework/Versions/A/Headers \
	   -I ../SDL2/SDL2_ttf.framework/Versions/A/Header \
	   -F ../SDL2/

FRAMEWORK =	-F ../SDL2 -framework SDL2 \
			-F ../SDL2 -framework SDL2_mixer \
			-F ../SDL2 -framework SDL2_ttf

all: $(NAME)

$(NAME): $(FILESO)
	make -C ../libft/src
	#make clean -C ../libft/src
	#$(FLAGS) -fsanitize=address -g
	gcc   -o $(NAME) $(SRC) $(INCL) $(LIBA) $(ADD) $(FRAMEWORK) $(HEADERS)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 SDL2/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer SDL2/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf SDL2/SDL2_ttf.framework/Versions/A/SDL2_ttf $(NAME)

objectives/%.o: srcs/%.c | objectives
	#$(FLAGS) -fsanitize=address -g
	gcc   $(INCL)  $(HEADERS) -o $@ -c $<

clean:
	rm -rf objectives/
	make clean -C ../libft/src

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft/src

objectives:
	mkdir objectives/

re: fclean all

NAME = doom

DATA_FILES = ft_atof.c\
				ft_new_load_data.c\
				ft_realloc.c\
				ft_scan_digit.c\
				ft_sect_data.c\
				ft_unload_data.c\
				ft_vert_data.c\
				ft_bmp_read_img.c\
				ft_create_items_data.c


MENU_FILES = ft_demons.c \
				ft_draw_ask_about_host.c\
				ft_draw_func.c\
				ft_draw_intro.c\
				ft_draw_net_game.c\
				ft_draw_net_part.c\
				ft_draw_something_er.c\
				ft_key.c\
				ft_key_handle.c\
				ft_main_loop.c\
				ft_menu.c\
				ft_menu_net.c\
				ft_menu_spec.c\
				ft_mouse.c\
				ft_net_client.c\
				ft_net_server.c\
				ft_network.c\
				ft_portal_animation.c\
				ft_tab_menu.c\
				ft_work_with_data.c\
				ft_work_with_text.c\
				ft_multiple_keys.c\
				ft_free_for_menu_tab.c \
				ft_init_sdl_load.c \
				ft_choose_map.c\
				ft_draw_choose_map.c\
				ft_mouse_maps.c\
				ft_send_map.c

RENDER_FILES = NEW_ft_engine_start.c\
				NEW_ft_see_points.c\
				ft_athens.c\
				ft_border_up_down.c\
				ft_cross_point.c\
				ft_prepare_to_draw.c\
				ft_try_ray.c \
				ft_player_input.c \
				ft_find_sector.c\
				ft_init_coef.c \
				ft_draw_floor.c \
				ft_draw_ceil.c \
				ft_gui.c\
				ft_aim.c\
				ft_shotgun.c\
				ft_pl_wsad.c\
				ft_draw_in.c\
				ft_top_bot.c\
				ft_portal_wall.c \
				ft_init_start_position.c\
				ft_collisions.c\
				ft_move_player.c\
				ft_intersection.c\
				ft_portal_or_wall.c\
				ft_blood_mask.c \
				ft_draw_aid.c



SECONDARY_FILES = NEW_ft_geom_oper.c\
					ft_lst_func.c\
					ft_music.c\
					ft_secondary.c\
					ft_secondary_2.c\
					ft_times_of_day.c\
					ft_prints.c

FILES =	ft_draw_game.c\
		ft_start_game.c\
		main.c

MENU_SRC = $(addprefix menu/, $(MENU_FILES))

SECONDARY_SRC = $(addprefix secondary/, $(SECONDARY_FILES))

RENDER_SRC = $(addprefix render/, $(RENDER_FILES))

DATA_SRC = $(addprefix data/, $(DATA_FILES))

SRC = $(addprefix src/, $(FILES)) $(addprefix src/, $(MENU_SRC)) $(addprefix src/, $(SECONDARY_SRC)) $(addprefix src/, $(RENDER_SRC)) $(addprefix src/, $(DATA_SRC))

OBJ = $(addprefix objectives/, $(FILES:.c=.o)) $(addprefix objectives/, $(MENU_SRC:.c=.o)) $(addprefix objectives/, $(SECONDARY_SRC:.c=.o)) $(addprefix objectives/, $(RENDER_SRC:.c=.o)) $(addprefix objectives/, $(DATA_SRC:.c=.o))
HEADERS = -I include -I libft/include  -I libft/src
ADD = -framework OpenGL -framework AppKit
INCL = -I.  -I src/ \
		-I SDL2/SDL2.framework/Versions/A/Headers \
		-I SDL2/SDL2_image.framework/Versions/A/Header \
		-I SDL2/SDL2_net.framework/Versions/A/Header \
		-I SDL2/SDL2_ttf.framework/Versions/A/Header \
		-I SDL2/SDL2_mixer.framework/Versions/A/Header \
		-F SDL2/
FRAMEWORK = -F SDL2 -framework SDL2\
			-F SDL2 -framework SDL2_image\
			-F SDL2 -framework SDL2_net\
			-F SDL2 -framework SDL2_mixer\
			-F SDL2 -framework SDL2_ttf

FLAGS = -Wall -Wextra -Werror

LFT = -L libft/src -lft

all:
	make startuem -j8

startuem: compile $(NAME)

compile:
	make -C ./libft/src -j8
	make -C ./editor -j8

$(NAME): $(OBJ)
	#$(FLAGS) -fsanitize=address -g
	#-fsanitize=address -g
	gcc  -o $(NAME) $(SRC) $(INCL) $(LFT) $(ADD) $(FRAMEWORK) $(HEADERS)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 SDL2/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer SDL2/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@install_name_tool -change @rpath/SDL2_image.framework/Versions/A/SDL2_image SDL2/SDL2_image.framework/Versions/A/SDL2_image $(NAME)
	@install_name_tool -change @rpath/SDL2_net.framework/Versions/A/SDL2_net SDL2/SDL2_net.framework/Versions/A/SDL2_net $(NAME)
	@install_name_tool -change @rpath/SDL2_ttf.framework/Versions/A/SDL2_ttf SDL2/SDL2_ttf.framework/Versions/A/SDL2_ttf $(NAME)

objectives/%.o: src/%.c | objectives
	#-fsanitize=address -g
	gcc  $(INCL) $(HEADERS)  -o $@ -c $<


clean:
	rm -rf objectives/
	make clean -C ./libft/src
	make clean -C ./editor

fclean: clean
	rm -Rf $(NAME)
	rm -rf $(NAME).dSYM
	make fclean -C ./libft/src
	make fclean -C ./editor

objectives:
	mkdir objectives/
	mkdir objectives/menu
	mkdir objectives/render
	mkdir objectives/secondary
	mkdir objectives/data

re: fclean
	make

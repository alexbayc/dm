# include <time.h>
# define NSEC_PER_SEC 1000000000
# define TICKS_PER_SECOND 4
# define SKIP_TICKS 1000 / TICKS_PER_SECOND
# define MAX_FRAMESKIP 3

long int			ft_get_tick_count(long int *start)
{
	long int		res;
	struct timespec time;

	clock_gettime(CLOCK_REALTIME, &time);
	res = ((time.tv_sec * NSEC_PER_SEC + time.tv_nsec)) - *start;
	return (res / 1000000);
}


int -main()
{
	t_game			game;
	struct timespec time;
	long int		next_game_tick;
	int				loops;

	if (!(game.ranning = ft_sdl_init(&game, 0)))
		ft_putendl("Error SDL_Init");
	// game.texture[0] = ft_bmp_read("fire/1.bmp");
	// game.texture[1] = ft_bmp_read("fire/2.bmp");
	// game.texture[2] = ft_bmp_read("fire/3.bmp");
	// game.texture[3] = ft_bmp_read("fire/4.bmp");
	clock_gettime(CLOCK_REALTIME, &time);
	game.start_time = (time.tv_sec * NSEC_PER_SEC + time.tv_nsec);

	next_game_tick = ft_get_tick_count(&game.start_time);
	SDL_SetRenderDrawColor(game.rend, 0, 0, 0, 0);
	SDL_RenderClear(game.rend);
	while (game.ranning)
	{
		loops = 0;
		ft_events(&game);
		while (ft_get_tick_count(&game.start_time) > next_game_tick
				&& loops < MAX_FRAMESKIP)
		{
			// ft_update(&game);
			// SDL_RenderPresent(game.rend);
			next_game_tick += SKIP_TICKS;
			loops++;
		}
	}
	return (0);
}
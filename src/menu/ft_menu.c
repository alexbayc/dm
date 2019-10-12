#include "engine.h"

void			ft_choose_back(t_engine *e)
{
	int	h;

	h = ft_time();
	//h = 10;
	//h = 13;
	//h = 18;
	//h = 3;

	if (h < 0)
		ft_return("error: time");
	if (h >= 6 && h < 12)
		ft_load_img_music_menu(e, "src/images/morning.png",
			"src/music/morning_birds.mp3");
	else if (h >= 12 && h < 17)
		ft_load_img_music_menu(e, "src/images/afternoon.png",
			"src/music/afternoon_lake_waves.mp3");
	else if (h >= 17 && h <= 23)
		ft_load_img_music_menu(e, "src/images/evening.png",
			"src/music/evening_waterfall.mp3");
	else if (h >= 0 && h < 6)
		ft_load_img_music_menu(e, "src/images/night.png",
			"src/music/night_crickets.mp3");
	if (!e->sdl.img_ptr || !e->mus.gmusic)
		ft_return("error: failed to load img or music!");
	if (Mix_PlayMusic(e->mus.gmusic, -1) == -1)
		ft_putendl("error: failed play music");
}

void			ft_background(t_engine *e)
{
	int	img_fl;

	img_fl = IMG_INIT_JPG | IMG_INIT_PNG;
	if (!(IMG_Init(img_fl) & img_fl))
		ft_return("error: IMG_Init Failed to init png support!");
	e->sdl.sur_ptr = SDL_GetWindowSurface(e->sdl.win_ptr);
	if (!e->sdl.sur_ptr)
		ft_return("error: failed to load screen!");
	if (!(IMG_Init(MIX_INIT_MP3)))
		ft_return("error: MIX_Init Failed");

	ft_load_img(e);
	ft_init_mus(e);
	ft_choose_back(e);
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_buttons_m(e);
}

static void		ft_create_window(t_engine *engine)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		ft_return("error: failed sdl init");
	engine->sdl.win_ptr = SDL_CreateWindow("Doom Nukem",
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									W, H,
									0);
	if (!engine->sdl.win_ptr)
		ft_return("error: failed to create window!");
	engine->menu_fl = 'Y';
	ft_background(engine);

	ft_init_chunks(engine);
}

void			ft_menu(t_engine *e)
{
	e->host_name = NULL;
	ft_create_window(e);
}

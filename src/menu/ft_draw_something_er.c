#include "engine.h"

static void		ft_buttons_err(t_engine *e, char *name)
{
	SDL_Rect	dest;
	t_text		tex;

	dest.x = 1400;
	dest.y = 600;
	if (!(e->sdl.but_start_ptr = IMG_Load(name)))
		ft_putendl("error: but");
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 90, dest.y + 180, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "UPS";
	ft_text(&tex, e);
	dest.y += 100;
	ft_fill_text_struct(&tex, dest.x + 90, dest.y + 140, 20);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "something went wrong";
	ft_text(&tex, e);
	SDL_FreeSurface(e->sdl.but_start_ptr);
	e->sdl.but_start_ptr = NULL;
	Mix_PlayChannel(-1, e->mus.err, 1);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	SDL_Delay(1500);
}

void			ft_draw_tired(t_engine *e)
{
	ft_buttons_err(e, "src/images/but_popup.png");
	printf("tired\n");
}

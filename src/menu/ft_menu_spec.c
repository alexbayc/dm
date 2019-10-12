#include "engine.h"

static void	ft_load(t_engine *e, SDL_Rect *dest)
{
	dest->x = 1400;
	dest->y = 0;
	e->menu_fl = 'Y';
	e->sdl.but_start_ptr = IMG_Load("src/images/but.png");
	if (!e->sdl.but_start_ptr)
		ft_return("error: img load");
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, dest);
}

static void	ft_map_editor_but(t_engine *e, SDL_Rect *dest, t_text *tex)
{
	dest->y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, dest);
	ft_fill_text_struct(tex, dest->x + 90, dest->y + 210, 40);
	ft_fill_text_struct_c(tex, 0x00, 0x60, 0x64);
	tex->text = "Map editor";
	ft_text(tex, e);
}

void	ft_buttons_m(t_engine *e)
{
	SDL_Rect	dest;
	t_text		tex;

	ft_load(e, &dest);
	ft_fill_text_struct(&tex, dest.x + 160, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "START";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 120, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "NETWORK";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "EXIT";
	ft_text(&tex, e);
	ft_map_editor_but(e, &dest, &tex);
	SDL_FreeSurface(e->sdl.but_start_ptr);
}

void	ft_menu_spec(t_engine *e)
{
	SDL_FreeSurface(e->sdl.img_ptr);
	e->sdl.img_ptr = NULL;
	Mix_FreeMusic(e->mus.gmusic);
	e->mus.gmusic = NULL;
	ft_choose_back(e);
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_buttons_m(e);
}

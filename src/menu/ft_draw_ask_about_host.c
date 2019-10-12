#include "engine.h"

static void		ft_fill(t_engine *e, SDL_Rect *dest, char *name)
{
	dest->x = 1400;
	dest->y = 0;
	e->menu_fl = 'M'; //M-means multiplayer mode
	e->sdl.but_start_ptr = IMG_Load(name);
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, dest);
}

static void		ft_if(t_engine *e, SDL_Rect dest, t_text *tex)
{
	if (e->host_name && ft_strlen(e->host_name) > 16)
		ft_fill_text_struct(tex, dest.x + 90, dest.y + 210, 18);
	else
		ft_fill_text_struct(tex, dest.x + 90, dest.y + 210, 25);
}

static void		ft_buttons(t_engine *e, char *name)
{
	SDL_Rect	dest;
	t_text		tex;

	ft_fill(e, &dest, name);
	ft_fill_text_struct(&tex, dest.x + 90, dest.y + 180, 18);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "Enter";
	ft_text(&tex, e);
	ft_fill_text_struct(&tex, dest.x + 85, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "HOST NAME:";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	tex.text = e->host_name;
	ft_if(e, dest, &tex);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "BACK";
	ft_text(&tex, e);
}

void			ft_draw_ask_about_host(t_engine *e)
{
	ft_putendl("here net client");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_buttons(e, "src/images/but.png");
	SDL_FreeSurface(e->sdl.but_start_ptr);
}

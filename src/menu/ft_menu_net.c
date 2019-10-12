#include "engine.h"

static void		ft_buttons(t_engine *e)
{
	SDL_Rect	dest;
	t_text		tex;

	dest.x = 1400;
	dest.y = 0;
	//e->menu_fl = 'M'; //M-means multiplayer mode
	e->sdl.but_start_ptr = IMG_Load("src/images/but.png");
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "HOST";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 160, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "CLIENT";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "BACK";
	ft_text(&tex, e);
	SDL_FreeSurface(e->sdl.but_start_ptr);
}

void		ft_menu_net(t_engine *e)
{
	printf("menu net here draw\n");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_buttons(e);
}

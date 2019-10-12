#include "engine.h"

void	ft_buttons_t(t_engine *e)
{
	SDL_Rect	dest;
	t_text		tex;

	dest.x = 1400;
	dest.y = 0;
	e->sdl.but_start_ptr = IMG_Load("src/images/but.png");
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 160, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "MENU";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 120, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "CONTINUE";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "EXIT";
	ft_text(&tex, e);
	SDL_FreeSurface(e->sdl.but_start_ptr);

}

void	ft_tab_menu(t_engine *e)
{
	if (Mix_PlayingMusic() == 1)
		Mix_PauseMusic();
	SDL_FreeSurface(e->sdl.img_ptr);
	e->sdl.img_ptr = NULL;
	e->sdl.img_ptr = IMG_Load("src/images/tab_menu.png");
	if (!e->sdl.img_ptr)
		ft_return("error: load img");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	e->menu_fl = 'D'; //tab menu
	SDL_SetRelativeMouseMode(SDL_FALSE);
	ft_buttons_t(e);
}

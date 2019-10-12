#include "engine.h"

void	ft_dead(t_engine *e)
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
	dest.y +=200;
	ft_fill_text_struct(&tex, dest.x - 750, dest.y + 170, 80);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "Game over!";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "EXIT";
	ft_text(&tex, e);
	SDL_FreeSurface(e->sdl.but_start_ptr);

}

void	ft_blood_mask(t_engine *e)
{
	if (e->player.health < 30)
		SDL_BlitSurface(e->sdl.blood_mask, NULL, e->sdl.sur_ptr, NULL);
	if (e->player.health <= 0)
	{
		ft_bzero(e->sdl.sur_ptr->pixels, sizeof(int) * H * W);
		SDL_BlitSurface(e->sdl.blood_mask, NULL, e->sdl.sur_ptr, NULL);
		SDL_SetRelativeMouseMode(SDL_FALSE);
		ft_dead(e);
		e->mouse_fl = 'Y';
	}
}
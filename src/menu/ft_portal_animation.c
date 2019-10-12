#include "engine.h"

void		ft_portal_sup(t_engine *e, SDL_Rect dest, SDL_Rect src, t_anim a)
{
	t_anim		tmp;
	SDL_Rect	src_tmp;

	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_memcpy(&tmp, &a, sizeof(t_anim));
	ft_memcpy(&src_tmp, &src, sizeof(SDL_Rect));
	while (tmp.i < tmp.lim_sp)
	{
		src_tmp.x = tmp.i * src_tmp.w;
		if (src_tmp.x >= tmp.lim_w)
		{
			src_tmp.y = tmp.i * src_tmp.h;
			if (src_tmp.y >= tmp.lim_h)
				break ;
			src.x = 0;
		}
		SDL_BlitSurface(tmp.p_ptr, &src_tmp, e->sdl.sur_ptr, &dest);
		SDL_UpdateWindowSurface(e->sdl.win_ptr);
		ft_delay_sec(1);
		tmp.i++;
	}
}

static void	ft_fill_tex(SDL_Rect *dest, SDL_Rect *src, t_engine *e)
{
	dest->x = 800;
	dest->y = 800;
	src->x = 0;
	src->y = 0;
	src->w = 182;
	src->h = 206;
}

void	ft_portal_animation(t_engine *e, t_anim p, t_text tex)
{
	SDL_Rect	dest;
	SDL_Rect	src;

	ft_fill_tex(&dest, &src, e);
	tex.text = "Devil's portal has been opened.";
	ft_fill_text_struct(&tex, 50, 180, 40);
	ft_fill_text_struct_c(&tex, 0xA6, 0x78, 0x00);
	ft_text(&tex, e);
	tex.text = "The undead have come to take over our world.";
	ft_fill_text_struct(&tex, 50, 180 + 80, 40);
	ft_fill_text_struct_c(&tex, 0xA6, 0x78, 0x00);
	ft_text(&tex, e);
	p.p_ptr = IMG_Load("src/images/port.png");
	ft_portal_sup(e, dest, src, p);
	ft_demons_one(e);
	tex.text = "Only you, our faithful warrior,";
	ft_fill_text_struct(&tex, 50, 180, 40);
	ft_fill_text_struct_c(&tex, 0xA6, 0x78, 0x00);
	ft_text(&tex, e);
	tex.text = "can save us and our land.";
	ft_fill_text_struct(&tex, 50, 180 + 80, 40);
	ft_fill_text_struct_c(&tex, 0xA6, 0x78, 0x00);
	ft_text(&tex, e);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(4);
}

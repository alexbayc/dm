#include "engine.h"

static void	ft_flags(t_engine *e, t_anim *p)
{
	e->menu_fl = 'G';
	e->mouse_fl = 'G';
	e->net_fl = 'N';
	e->host_fl = 'N';
	e->client_fl = 'N';
	p->lim_h = 824;
	p->lim_w = 728;
	p->i = 0;
}

static void	ft_draw_storm(t_engine *e, char *str)
{
	e->sdl.img_ptr = IMG_Load(str);
	if (e->sdl.img_ptr == NULL)
		ft_return("error: load img");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
}

static void	ft_draw_slides(t_engine *e, SDL_Rect dest, t_text tex, char *name)
{
	if (!(e->sdl.img_ptr = IMG_Load(name)))
		ft_return("error: load img");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_fill_text_struct(&tex, dest.x + 90, dest.y + 180, 40);
	if (ft_strstr(name, "storm") == NULL)
		ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	else
		ft_fill_text_struct_c(&tex, 0xA6, 0x78, 0x00);
	ft_text(&tex, e);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
}

static void	ft_draw_cartoon(t_engine *e, SDL_Rect dest, t_text tex)
{
	ft_music_stop_start(e, "src/music/morning_birds.mp3");
	tex.text = "We used to live in peace and harmony";
	ft_draw_slides(e, dest, tex, "src/images/intro_new.png");
	ft_delay_sec(4);
	ft_music_stop_start(e, "src/music/thunder2.mp3");
	tex.text = "But the great";
	ft_draw_slides(e, dest, tex, "src/images/storm2_1.png");
	ft_delay_sec(3);
	tex.text = "storm began";
	ft_draw_slides(e, dest, tex, "src/images/storm2_2.png");
	ft_delay_sec(3);
}

void		ft_draw_intro(t_engine *e)
{
	SDL_Rect	dest;
	t_text		tex;
	t_anim		p;

	ft_bzero(&dest, sizeof(SDL_Rect));
	ft_flags(e, &p);
	ft_draw_cartoon(e, dest, tex);
	ft_draw_storm(e, "src/images/storm2_3.png");
	ft_draw_storm(e, "src/images/storm2_4.png");
	ft_portal_animation(e, p, tex);
}

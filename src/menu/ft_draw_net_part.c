#include "engine.h"

static char		*ft_get_my_name(void)
{
	char	*str;
	int		fd;
	int		rez;

	if (system("sh ./scripts/whoami.sh") == -1)
		ft_return("error: system");
	fd = open("./scripts/rez_whoami.txt", O_RDONLY);
	if (fd < 0)
		ft_return("error: system");
	rez = get_next_line(fd, &str);
	if (rez <= 0)
		ft_return("error: gnl");
	close(fd);
	if (system("rm -f ./scripts/rez_whoami.txt") == -1)
		ft_return("error: system2");
	return (str);
}

static void		ft_fill(t_engine *e, SDL_Rect *dest, char *name)
{
	dest->x = 1400;
	dest->y = 0;
	e->menu_fl = 'M'; //M-means multiplayer mode
	e->sdl.but_start_ptr = IMG_Load(name);
	if (!(e->sdl.but_start_ptr))
		ft_return("error: load");
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, dest);
}

static void		ft_buttons(t_engine *e, char *name)
{
	SDL_Rect	dest;
	t_text		tex;

	ft_fill(e, &dest, name);
	ft_fill_text_struct(&tex, dest.x + 90, dest.y + 180, 18);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "Host name is:";
	ft_text(&tex, e);
	ft_fill_text_struct(&tex, dest.x + 85, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = ft_get_my_name();
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_strdel(&tex.text);
	ft_fill_text_struct(&tex, dest.x + 120, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "WAITING...";
	ft_text(&tex, e);
	dest.y += 200;
	SDL_BlitSurface(e->sdl.but_start_ptr, NULL, e->sdl.sur_ptr, &dest);
	ft_fill_text_struct(&tex, dest.x + 180, dest.y + 210, 40);
	ft_fill_text_struct_c(&tex, 0x00, 0x60, 0x64);
	tex.text = "BACK";
	ft_text(&tex, e);
}

void	ft_draw_waiting_list(t_engine *e)
{
	ft_putendl("draw");
	SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
	ft_buttons(e, "src/images/but.png");
	SDL_FreeSurface(e->sdl.but_start_ptr);
}


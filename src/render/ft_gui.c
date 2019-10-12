#include "engine.h"

static void	ft_level(t_engine *e)
{
	char	*str;

	str = ft_itoa(e->player.level);
	if (!str)
		ft_return("erro: malloc");
	if (!(e->sdl.text.text = ft_strjoin("level ", str)))
		ft_return("erro: malloc");
	ft_strdel(&str);
	ft_fill_text_struct(&e->sdl.text, e->sdl.destin.x + 230,
		e->sdl.destin.y + 145, 18);
	ft_fill_text_struct_c(&e->sdl.text, 0xff, 0xff, 0xff);
	ft_text(&e->sdl.text, e);
	ft_strdel(&e->sdl.text.text);
}

static void	ft_ammo(t_engine *e)
{
	char	*str;
	char	*tmp;
	char	*str2;

	if (!(str = ft_itoa(e->player.ammo_max)))
		ft_return("erro: malloc");
	if (!(tmp = ft_strjoin("/", str)))
		ft_return("erro: malloc");
	ft_strdel(&str);
	if (!(str = ft_itoa(e->player.ammo)))
		ft_return("erro: malloc");
	if (!(str2 = ft_strjoin("ammo ", str)))
		ft_return("erro: malloc");
	ft_strdel(&str);
	e->sdl.text.text = ft_strjoin(str2, tmp);
	ft_strdel(&str2);
	ft_strdel(&tmp);
	if (!e->sdl.text.text)
		ft_return("error: malloc");
	ft_fill_text_struct(&e->sdl.text, e->sdl.destin.x + 230,
		e->sdl.destin.y + 95, 22);
	ft_fill_text_struct_c(&e->sdl.text, 0xff, 0xff, 0xff);
	ft_text(&e->sdl.text, e);
	ft_strdel(&e->sdl.text.text);
}

static void	ft_health(t_engine *e)
{
	char	*str;
	char	*str2;
	char	*tmp;

	if (!(str = ft_itoa(e->player.health_max)))
		ft_return("error: malloc");
	if (!(str2 = ft_strjoin("/", str)))
		ft_return("error: malloc");
	ft_strdel(&str);
	if (!(str = ft_itoa(e->player.health)))
		ft_return("error: malloc");
	if (!(tmp = ft_strjoin("health ", str)))
		ft_return("error: malloc");
	ft_strdel(&str);
	e->sdl.text.text = ft_strjoin(tmp, str2);
	ft_strdel(&tmp);
	ft_strdel(&str2);
	if (!e->sdl.text.text)
		ft_return("error: malloc");
	ft_fill_text_struct(&e->sdl.text, e->sdl.destin.x + 230,
		e->sdl.destin.y + 32, 28);
	ft_fill_text_struct_c(&e->sdl.text, 0xff, 0xff, 0xff);
	ft_text(&e->sdl.text, e);
	ft_strdel(&e->sdl.text.text);
}

void	ft_gui(t_engine *e)
{
	ft_level(e);
	ft_ammo(e);
	ft_health(e);
	ft_aim(e);
	ft_shotgun(e);
}

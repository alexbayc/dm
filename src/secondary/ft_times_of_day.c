#include "engine.h"

void	ft_load_img_music_menu(t_engine *e, char *img, char *music)
{
	e->sdl.img_ptr = IMG_Load(img); //утро
	if (e->sdl.img_ptr == NULL)
		ft_return("error: failed to load img!");
	ft_load_music(e, music);
}


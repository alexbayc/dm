#include "engine.h"

void	ft_music_stop_start(t_engine *e, char *str)
{
	if (Mix_PlayingMusic() == 1)
		Mix_HaltMusic();
	Mix_FreeMusic(e->mus.gmusic);
	e->mus.gmusic = NULL;
	ft_load_music(e, str);
	if (Mix_PlayMusic(e->mus.gmusic, -1) == -1)
		ft_putendl("error: failed play music");
}

void	ft_init_mus(t_engine *e)
{
	ft_bzero(&e->mus, sizeof(t_music));
	if (Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
	{
		ft_putendl("error: mixer");
		return ;
	}

}

void	ft_load_music(t_engine *e, char *name_file)
{
	if (e->mus.gmusic == NULL)
	{
		e->mus.gmusic = Mix_LoadMUS(name_file);
		if (e->mus.gmusic == NULL)
			ft_putendl("error: mixer");
	}
}

// void	ft_load_chunks(t_engine *e, char *name_file)
// {
// 	e->mus.effect = Mix_LoadWAV(name_file);
// 	if (e->mus.effect == NULL)
// 		ft_putendl("error: mixer");
// }

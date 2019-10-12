#include "engine.h"

void	ft_load_chunks(char *str, Mix_Chunk **ef)
{
	if (!str)
	{
		ft_putendl("no file name");
		return ;
	}
	*ef = Mix_LoadWAV(str);
	if (!*ef)
		ft_putendl("error: mixer");
}

void	ft_free_chunks(Mix_Chunk **ef)
{
	if (*ef)
		Mix_FreeChunk(*ef);
	*ef = NULL;
}

void	ft_init_chunks(t_engine *e)
{
	printf("load chunks\n");
	ft_load_chunks("src/music/bite.mp3", &e->mus.intro_bite);
	ft_load_chunks("src/music/step.mp3", &e->mus.steps);
	ft_load_chunks("src/music/error2.mp3", &e->mus.err);
	ft_load_chunks("src/music/shot.wav", &e->mus.shot);
	ft_load_chunks("src/music/empty.wav", &e->mus.empty);
	ft_load_chunks("src/music/jump.wav", &e->mus.jump);
	ft_load_chunks("src/music/hurt.wav", &e->mus.hurt);
	ft_load_chunks("src/music/game_over.wav", &e->mus.game_over);
	ft_load_chunks("src/music/select.wav", &e->mus.mouse);
}


void	ft_free_all_chunks(t_engine *e)
{
	printf("i free all chunks\n");
	ft_free_chunks(&e->mus.intro_bite);
	ft_free_chunks(&e->mus.steps);
	ft_free_chunks(&e->mus.err);
	ft_free_chunks(&e->mus.shot);
	ft_free_chunks(&e->mus.empty);
	ft_free_chunks(&e->mus.jump);
	ft_free_chunks(&e->mus.hurt);
	ft_free_chunks(&e->mus.game_over);
	ft_free_chunks(&e->mus.mouse);
}




void	ft_load_img(t_engine *e)
{
	e->sdl.aim = IMG_Load("src/images/aim.png");
	e->sdl.gui = IMG_Load("src/images/gui.png");
	e->sdl.blood_mask = IMG_Load("src/images/blood.png");
	if (!e->sdl.gui || !e->sdl.blood_mask || !e->sdl.aim)
		ft_return("error: img load");

}

void ft_free_image(SDL_Surface *img)
{
	if (img != NULL)
	{
		SDL_FreeSurface(img);
		img = NULL;
	}

}


void	ft_free_img(t_engine *e)
{
	if ( e->sdl.aim)
	{
		SDL_FreeSurface(e->sdl.aim);
		e->sdl.aim = NULL;
	}
	if (e->sdl.gui)
	{
		SDL_FreeSurface(e->sdl.gui);
		e->sdl.gui = NULL;
	}
	if (e->sdl.blood_mask)
	{
		SDL_FreeSurface(e->sdl.blood_mask);
		e->sdl.blood_mask = NULL;
	}


}

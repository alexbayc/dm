#include "engine.h"

void	ft_fill_text_struct(t_text *t, int x, int y, int sz)
{
	t->x = x;
	t->y = y;
	t->size = sz;
}

void	ft_fill_text_struct_c(t_text *t, int r, int g, int b)
{
	t->r = r;
	t->g = g;
	t->b = b;
}

void	ft_text(t_text *t, t_engine *e)
{
	SDL_Color	clr;
	SDL_Rect	dest;
	TTF_Font	*fnt;
	SDL_Surface	*text_surface;

	clr.r = t->r;
	clr.g = t->g; // Зададим параметры цвета
	clr.b = t->b;
	if (TTF_Init() < 0)
		ft_return("error: ttf init");
	fnt = TTF_OpenFont("src/images/bat.ttf", t->size); // Загружаем шрифт по заданному адресу размером sz
	dest.x = t->x;
	dest.y = t->y;
	text_surface = TTF_RenderText_Solid(fnt, t->text, clr);
	//SDL_Surface * TextSurface = TTF_RenderText_Blended(fnt, text, clr); // Переносим на поверхность текст с заданным шрифтом и цветом сглаживания
	SDL_BlitSurface(text_surface, NULL, e->sdl.sur_ptr, &dest);
	SDL_FreeSurface(text_surface); // Освобождаем память уже ненужной поверхности
	TTF_CloseFont(fnt); // Закрываем шрифт
}

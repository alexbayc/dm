#include "engine.h"

int main(int argc, char **argv)
{
	// loop back
	// 127.0.0.1

	t_engine e;
	ft_bzero(&e, sizeof(t_engine));
	e.fl_select = 0;
	//ft_choose_map(&e);
	e.map_choosen = 0;
	e.choose_map = 0;

	e.player.health = 1;
	if (argc == 1)
		e.map = "map-clear.txt";
	else
		e.map = argv[1];
	ft_menu(&e);
	ft_general_loop(&e);
	ft_close(&e);


	return (0);
}

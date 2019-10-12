#ifndef ENGINE_H
# define ENGINE_H
# include <math.h>
# include "for_norm_structs.h"
# include <stdio.h>
# include <time.h>
# include <SDL2/SDL.h>
# include	"libft.h"
/* mac os */
# include <SDL2_image/SDL_image.h>
# include <SDL2_net/SDL_net.h>
# include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

/* linux
# include "../../../usr/include/SDL2/SDL_image.h"
# include "../../../usr/include/SDL2/SDL_net.h"
# include "../../../usr/include/SDL2/SDL_ttf.h"
# include "../../../usr/include/SDL2/SDL_mixer.h"
*/

# define PI 3.1415926535897932384626433832795

# define W 1920
# define H 1080

# define A 60
# define B 60
# define FOV_D 30
/* size of buffers for network */
# define S 50



# define EyeHeight 6

typedef struct	s_img
{
	unsigned int *img;
	int w;
	int h;
}				t_img;

typedef struct	s_bmp
{
	Uint16		bf_type;
	Uint32		bf_size;
	Uint32		bf_reserved;
	Uint32		bf_off_bits;
	Uint32		bi_size;
	Uint32		bi_width;
	Uint32		bi_height;
	Uint16		bi_planes;
	Uint16		bi_bit_count;
	Uint32		bi_compression;
	Uint32		bi_size_image;
	Uint32		bi_x_pels_per_meter;
	Uint32		bi_y_pels_per_meter;
	Uint32		bi_color_used;
	Uint32		bi_color_important;
}				t_bmp;


typedef struct	s_item
{
	int		sectorno;
	int		sx1;
	int		sx2;
}				t_item;

typedef struct	s_xy
{
	double		x;
	double		y;
}				t_xy;

typedef struct	s_sector
{
	float		floor;
	float		ceil;
	t_xy		*vertex;
	signed char *neighbors;
	unsigned	npoints;
	int			*texturs;
}				t_sector;



typedef struct	s_anim
{
	int			lim_sp;
	SDL_Surface	*p_ptr;
	int			lim_h;
	int			lim_w;
	int			i;
}				t_anim;

typedef struct	s_ijk
{
	int			i;
	int			j;
	int			k;
}				t_ijk;

typedef struct	s_xyz
{
	float		x;
	float		y;
	float		z;
}				t_xyz;

typedef	struct	s_player
{
	t_xyz		where;

	float		height;
	float		angle;
	float		fov_d;
	unsigned	sector;
	int			level;
	int			health;
	int			health_max;
	int			ammo;
	int			ammo_max;
	/*for new engine*/
	int			h_l;
	float		speed;
	int			jump;
	int			soar;
	char		shot;
	int			shoot;
	int			seat;
	int			squats;
}				t_player;


typedef	struct	s_mobs
{
	t_xyz		where;
	int			status;
	int			type;
	int			damage;
	int			height;
	float		angle;
	int			sector;
	int			x;
	int			y;
}				t_mobs;



typedef struct	s_music
{
	//The music that will be played
	Mix_Music *gmusic;
	//The sound effects that will be used
	Mix_Chunk *intro_bite;
	Mix_Chunk *steps;
	Mix_Chunk *err;
	Mix_Chunk *shot;
	Mix_Chunk *empty;
	Mix_Chunk *jump;
	Mix_Chunk *hurt;
	Mix_Chunk *game_over;
	Mix_Chunk *mouse;


	/* data */
}				t_music;

/* that struct for transmit and recive*/
typedef struct	s_data
{
	int	x;
	int	y;
}				t_data;

typedef struct	s_text
{
	int			x;
	int			y;
	char		*text;
	int			size;
	int			r;
	int			g;
	int			b;
}				t_text;

typedef struct	s_sdl
{
	SDL_Window	*win_ptr; //SDL_Window	*window;
	SDL_Surface	*sur_ptr; //SDL_Surface	*screen;
	SDL_Surface	*img_ptr;

	SDL_Surface	*but_start_ptr;
	SDL_Surface	*aim;
	SDL_Surface	*gui;
	SDL_Surface	*blood_mask;



	SDL_Event	event;
	SDL_Rect	destin;
	t_text		text;
	t_xyz		cam;
}				t_sdl;

typedef struct	s_true_p
{
	t_xy	t;
	char	after_w;
	struct s_true_p *next;
	struct s_true_p *prev;
}				t_true_p;

typedef struct	s_draw
{
	uint32_t	sector;
	double		left;
	double		right;
	int			h;
	int			w;
	int			x_s;
	int			y_s;
	int			razn_top;
	int			razn_bot;
	int			half;
}				t_draw;


typedef struct	s_engine
{
	t_sdl		sdl; //замолочить ее
	t_music		mus;
	int			mouse_iter;
	/* for net */
	char		*host_name;
	int			port;
	IPaddress	ip;
	TCPsocket	client;
	TCPsocket	server;
	t_data		*data_my;
	t_data		*data_another; /*serv o client depends on flag*/
	t_data		*data_tmp;

	char	*dat_my;
	char	*dat_anot;
	char	*dat_tmp;
	/* end of net */

	t_player	player;
	t_sector	*sectors;
	t_xy		*vert_new;
	t_co_trans		center;
	t_draw			draw_in;

	int			*top;
	int			*bot;

	unsigned	num_sectors;

	/* flags */
	/* i chose char because 1 weight */
	/* mb i create struct of fl */
	/* Y-Yes, N-No, NUll */
	char			menu_fl;
	char			net_fl;
	char			host_fl;
	char			client_fl;
	char			mouse_fl;
	char			net_err_fl;
	char			vist_net_fl;
/*choose and transmitte map */
	char			choose_map;
	char			**maps;
	int				nb_map;
	int				max_len_name_map;
	char			fl_select;
	char			map_choosen;

	t_img			*shotgun[4];
	t_img			*wall_text;
	t_img			*aid;

	int				m_x;
	int				m_y;
	unsigned char	visited[32];
	unsigned char	to_visit[32];
	Uint8 			*keystates;
	char			*map;
	/*mobs and items */
	t_mobs			*mobs;
	int				nb_mobs;



}				t_engine;

/*engine func true*/
void					ft_engine_start(t_engine *e);
t_true_p				*ft_del_minus_points(t_engine *e);
void					ft_true_p(t_engine *e);
void					ft_trans(double *x, double *y, t_co_trans *o);
void					ft_brasenham(t_double k, int **mas);
void					ft_transfer_img_to_null(t_engine *e, t_true_p	**l);
void					ft_try_ray(t_engine *e, t_true_p **l);
int						ft_which_sector(t_engine *e, float x, float y);
void					ft_draw_ceil(t_engine *e, double *ray);
void					ft_draw_floor(t_engine *e, double *ray);

void	ft_draw_in(t_engine *e, t_true_p **l, int **walls);
void	ft_top_bot(t_engine *e, double *ray);
void	ft_init_start_posotion(t_engine *e);


void	ft_printf(char *str, t_engine *e, int i);

/*read data */
t_img		*ft_bmp_read_img(char *file);
void		ft_shotgun(t_engine *e);

void		ft_create_items_data(t_engine *e, char *gnl);
void		ft_fill_sectors_2(t_engine *e);
void		ft_put_another_pl(t_engine *e, char *gnl);
void		ft_fill_items_mass(t_engine *e, char *gnl);

/*free */
void	ft_free_all_in_engine(t_engine *e);
void	ft_free_sectors(t_engine *e);
void	ft_free_img(t_engine *e);

/*player motion*/
void	ft_w(t_engine *e);
void	ft_s(t_engine *e);
void	ft_a(t_engine *e);
void	ft_d(t_engine *e);
void	ft_jump(t_engine *e);
void	ft_horizon(t_engine *e, int x, int y);

void	ft_activate_shoot(t_engine *e);
void	ft_ml_player_input(t_engine *e, Uint8 *state);
void	ft_seat(t_engine *e);
void	ft_stand_up(t_engine *e);
/*collisions*/
void	ft_collision(t_engine *e, t_xyz *p);
int		ft_portal_or_wall(t_engine *e, t_xyz *p, int sec, int sec_now);
int			ft_intersect(t_xy a, t_xy b, t_xy c, t_xy d);

/* draw func */
void	ft_draw_game(t_engine *e);
void	ft_draw_func(t_engine *e);
void	ft_main_loop(t_engine *e, SDL_Thread	**thread);
void	ft_general_loop(t_engine *e);
void	ft_draw_net_game(t_engine *e);
void	ft_draw_intro(t_engine *e);
void	ft_blood_mask(t_engine *e);
void	ft_draw_choose_map(t_engine *e);

void	ft_draw_aid(t_engine *e);


/* animation */
void	ft_portal_animation(t_engine *e, t_anim p, t_text tex);
void	ft_demons_one(t_engine *e);
/* secondary func */
void		ft_return(char *str);
int			ft_time ();
void		ft_delay_sec(int sec);
void		ft_surface_set_pixel(SDL_Surface *surface, int x, int y, Uint32 color);
Uint32		ft_surface_get_pixel(SDL_Surface *sur, int x, int y);

double			ft_rad_to_dig(double rad);
double			ft_dig_to_rad(float angle);

void		ft_print_lst(t_true_p **head);
void		ft_print_mas(t_xyz *mas, int len);
void		ft_print_border(int *mas, int len);

void		ft_add_node(t_true_p **head, t_xy l, char aft);
void		ft_add_node_next(t_true_p **is, t_xy l, char aft);
void		ft_add_node_prev(t_true_p **is, t_xy l, char aft);
void		ft_add_node_head_prev(t_true_p **is, t_xy l, char aft);

int			ft_lst_len(t_true_p **head);
float		ft_modul(float x);
t_true_p	*ft_get_node(t_true_p **head, int i);
t_true_p	*ft_get_last(t_true_p **head);
void	ft_free_lst(t_true_p **head);
void	ft_reverse_mas(double **ray, t_engine *e);
void	ft_print_t_xy_lst(t_xy *print, t_engine *e);

/* key event */
int				ft_ch_key(t_engine *e);
int				ft_ch_mouse(t_engine *e);
int				ft_exit_x(t_engine *e);
void			ft_close(t_engine *e);
void			ft_close_net(t_engine *e);
/* menu func */
void	ft_menu(t_engine *e);
void	ft_background(t_engine *e);
void	ft_choose_back(t_engine *e);
void	ft_buttons_m(t_engine *e);

void	ft_menu_net(t_engine *e);
void	ft_menu_spec(t_engine *e);
void	ft_tab_menu(t_engine *e);
void	ft_check_tab_zone(t_engine *e);
void	ft_fill_for_g(t_engine *e);
void	ft_get_map_name(t_engine *e);

/* net host */
void	ft_net_server(t_engine *e);
int		ft_listening(t_engine *e);
void	ft_draw_waiting_list(t_engine *e);
void	ft_draw_tired(t_engine *e);

int		ft_connect(void *data);
void	ft_loop_net(t_engine *e);
void	ft_choose_map(t_engine *e);
void	ft_mouse_maps(t_engine *e);
void	ft_mouse_maps_select(t_engine *e);
void	ft_mouse_maps(t_engine *e);
void	ft_send_map(t_engine *e);
void	ft_free_mass(char ***str);


/* net client */
void	ft_handle_key(t_engine *e);
void	ft_ready_host_name(t_engine *e);
void	ft_back_space(t_engine *e);
void	ft_net_client(t_engine *e);
void	ft_draw_ask_about_host(t_engine *e);
void	ft_get_map_name(t_engine *e);

/* work with text */
void		ft_text(t_text *t, t_engine *e);
void		ft_fill_text_struct_c(t_text *t, int r, int g, int b);
void		ft_fill_text_struct(t_text *t, int x, int y, int sz);

/* sdl init */
void	ft_init_sdl(t_engine *e);
void	ft_create_struct_another(t_engine *e, int x, int y);
void	ft_create_struct_my(t_engine *e, int x, int y);
/*images */
void	ft_load_img(t_engine *e);
/* music */
void	ft_init_mus(t_engine *e);
void	ft_load_music(t_engine *e, char *name_file);
//void	ft_load_chunks(t_engine *e, char *name_file);
void	ft_music_stop_start(t_engine *e, char *str);
void	ft_load_img_music_menu(t_engine *e, char *img, char *music);
void	ft_init_chunks(t_engine *e);
void	ft_free_all_chunks(t_engine *e);


/* load data */
float			ft_atof(const char *str);
float			ft_scan_digit(char **str);
int				ft_new_load_data(t_engine *engine, char *file);
void			*ft_realloc(void *mem, int size, size_t segment);
int				ft_sect_data(t_engine *engine, t_xy *vert, char *gnl);
int				ft_vert_data(t_xy **vert_main, char *gnl, int *num_vert);

/* rendder */
void			ft_init_coef(t_engine *e);
void			ft_render(t_engine *e);
void			ft_start_game(t_engine *engine);
void			ft_mouse_game(t_engine *e);
void			ft_player_input(t_engine *e);
void			ft_fill_o(t_engine *e, t_co_trans *o);
void			ft_parallel_transfer(t_engine *e, t_co_trans *o);
void			ft_draw_portal_wall(t_engine *e, double *ray, int *wall, t_ijk ijk);

t_xy		*ft_cross_point(t_xy p0, t_xy p1, t_xy pr);

/* gui bar */
void	ft_gui(t_engine *e);
void	ft_load_and_blit(t_engine *e);
void	ft_aim(t_engine *e);

/* geom functions */

double			ft_cross_product(double x0, double y0, double x1, double y1);
double			ft_angle_vectors(double x0, double y0, double x1, double y1);

#endif

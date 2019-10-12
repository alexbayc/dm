# ifndef FOR_NORM_STRUCTS_H
# define FOR_NORM_STRUCTS_H

typedef struct	s_co_trans
{
	double	x;
	double	y;
	double	angle;
	double	a;
	double	b;
}				t_co_trans;

typedef struct	s_int
{
	int			i;
	int			prev;
	int			next;
	float		*alpha;


}				t_int;

typedef struct		s_double
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
}					t_double;

typedef struct		s_b
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				x;
	int				y;
	int				i;
}					t_b;

typedef struct	s_cros_line
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	float	q0;
	float	p0;
}				t_cros_line;


typedef struct	s_map
{
	char *map;
	int	h;
	int	w;
}				t_map;

typedef struct	s_t_ray
{
	int	i;
	double	d_a;
}				t_t_ray;


#endif

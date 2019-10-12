#include "engine.h"

void	ft_rotate_x(double angle, t_xyz *mas)
{
	int	pr_y;

	pr_y = mas->y;
	mas->y = pr_y * cos(angle) + mas->z * sin(angle);
	mas->z = (-1) * pr_y * sin(angle) + mas->z * cos(angle);
}

void	ft_rotate_y(double angle, t_xyz *mas)
{
	int	pr_x;

	pr_x = mas->x;
	mas->x = pr_x * cos(angle) + mas->z * sin(angle);
	mas->z = (-1) * pr_x * sin(angle) + mas->z * cos(angle);
}

void	ft_rotate_z(double angle, t_xyz *mas)
{
	int	pr_x;
	int	pr_y;

	pr_x = mas->x;
	pr_y = mas->y;
	mas->x = pr_x * cos(angle) - pr_y * sin(angle);
	mas->y = (1) * pr_x * sin(angle) + pr_y * cos(angle);
}

#include "engine.h"

double			ft_dig_to_rad(float angle)
{
	double			new_angl;
	double			pi;

	pi = 3.1415926535;
	new_angl = (((double)angle) * pi) / 180.0f;
	return (new_angl);
}


double			ft_rad_to_dig(double rad)
{
	double		new_angl;
	double		pi;

	pi = 3.1415926535;
	new_angl = rad * 180.f / pi;
	return (new_angl);
}

double			ft_cross_product(double x0, double y0, double x1, double y1)
{
	return (x0 * y1 - y0 * x1);
}

double			ft_angle_vectors(double x0, double y0, double x1, double y1)
{
	// printf("sqrts %f\n",sqrt(x0 * x0 + x1 * x1) * sqrt(y0 * y0 + y1 * y1));
	// printf("%f %f %f %f\n", x0, y0, x1, y1);
	return (acos((x0 * x1 + y0 * y1) / (sqrt(x0 * x0 + y0 * y0) * sqrt(x1 * x1 + y1 * y1))));
}
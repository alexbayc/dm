#include "doom.h"

double			ft_dig_to_rad(int angle)
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

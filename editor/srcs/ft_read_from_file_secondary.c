#include "doom.h"

float	ft_scan_digit(char **str)
{
	float	res;
	char	*dest;

	res = ft_atof(*str);
	dest = *str;
	while (*dest && !ft_isdigit(*dest))
		dest++;
	while (*dest && ft_isdigit(*dest))
		dest++;
	if (*dest == '.')
	{
		dest++;
		while (*dest && ft_isdigit(*dest))
			dest++;
	}
	*str = dest;
	return (res);
}

float	ft_atof(const char *str)
{
	float	res;
	int		hvost;
	float	float_hvost;

	float_hvost = 0;
	res = (float)ft_atoi(str);
	while (*str == '\t' || *str == ' ')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str++ == '.')
	{
		hvost = ft_atoi(str);
		while (hvost)
		{
			float_hvost = float_hvost / 10 + hvost % 10;
			hvost /= 10;
		}
	}
	return (res + float_hvost / 10);
}

#include "engine.h"

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

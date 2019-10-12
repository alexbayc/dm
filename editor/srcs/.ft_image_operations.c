/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 15:08:08 by cmanfred          #+#    #+#             */
/*   Updated: 2019/03/26 15:25:08 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"
#include <stdio.h>

/*
 ** Function, that will free the image if something went wrong
*/

t_img		*ft_delimage(t_img *img)
{
	if (img != NULL)
	{
		if (img->img_ptr != NULL)
			mlx_destroy_image(img->mlx_ptr, img->img_ptr);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

/*
 ** User-friendly function, that sets pixel in the image, using it's formatted
 ** X and Y coordinates
*/

void		ft_image_set_pixel(t_img *image, int x, int y, int color)
{
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return ;
	*(int *)(image->adr + (x * image->bitspp + y * image->size_line)) = color;
}

int			ft_get_pixel(t_img *image, int x, int y)
{
	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return (0);
	return (*(int *)(image->adr + ((x + y * image->width)
					* image->bitspp)));
}

/*
 ** Function, that allocates new image
*/

void		ft_new_image(t_img *img)
{
	if ((img->img_ptr = mlx_new_image(img->mlx_ptr, img->width,
		img->height)) == NULL)
	{
		(ft_delimage(img));
		return ;
	}
	img->adr = mlx_get_data_addr(img->img_ptr, &img->bitspp, &img->size_line,
			&img->endian);
	img->bitspp /= 8;
}

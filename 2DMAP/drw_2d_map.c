/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:02:11 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	pixelget(t_cubd *cub, int x, int y, int i)
{
	char	*color;

	color = cub->tx[i].add + y * cub->tx[i].len + x
		* (cub->tx[i].bp / 8);
	return (*(int *)color);
}

int	new_map(t_cubd *cub)
{
	mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, WIN_WITH, WIN_HIGHT);
	cub->add = (int *)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
	draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

void	norm_ray_distance(t_cubd *cub, double x_check, double y_check, int ray)
{
	cub->rays[ray]->wallhitx = x_check;
	cub->rays[ray]->wallhity = y_check;
	cub->rays[ray]->projectiowalls = (TILE_SIZE / cub->rays[ray]->distance)
		* cub->rays[ray]->projectionplan;
	cub->rays[ray]->wallsheight = (int)cub->rays[ray]->projectiowalls;
	cub->rays[ray]->walltoppixel = (WIN_HIGHT / 2)
		- (cub->rays[ray]->wallsheight / 2);
	if (cub->rays[ray]->walltoppixel < 0)
		cub->rays[ray]->walltoppixel = 0;
	else
		cub->rays[ray]->walltoppixel = cub->rays[ray]->walltoppixel;
	cub->rays[ray]->wallbottompixel = (WIN_HIGHT / 2)
		+ (cub->rays[ray]->wallsheight / 2);
	if (cub->rays[ray]->wallbottompixel > WIN_HIGHT)
		cub->rays[ray]->wallbottompixel = WIN_HIGHT;
	else
		cub->rays[ray]->wallbottompixel = cub->rays[ray]->wallbottompixel;
}

void	ray_distance(t_cubd *cub, double rangl, int ray)
{
	double	i;
	double	x_check;
	double	y_check;
	double	ds;

	i = 0;
	cub->rays[ray]->projectionplan = (WIN_WITH / 2) / tan(FOV_ANGLE / 2) - 150;
	while (i >= 0 && (i < WIN_WITH || i < WIN_HIGHT))
	{
		x_check = cub->x_p - cos(rangl) * i;
		y_check = cub->y_p - sin(rangl) * i;
		if (!map_has_wall(cub, x_check, y_check)
			|| !map_has_wall(cub, x_check, cub->y_p - sin(rangl) * (i - 1))
			|| !map_has_wall(cub, cub->x_p - cos(rangl) * (i - 1), y_check))
		{
			cub->rays[ray]->rangl = rangl;
			ds = calculate_distance(cub, (cub->x_p - cos(rangl) * i),
					(cub->y_p - sin(rangl) * i));
			cub->rays[ray]->distance = ds
				* cos(cub->rays[ray]->rangl - cub->ang);
			norm_ray_distance(cub, x_check, y_check, ray);
			break ;
		}
		i += 1;
	}
}

void	draw_rays(t_cubd *cub)
{
	double	rangl;
	int		ray;
	int		i;

	i = 0;
	rangl = cub->ang - 0.5235;
	ray = 0;
	while (rangl < cub->ang + 0.5235)
	{
		ray_distance(cub, rangl, ray);
		rangl += FOV_ANGLE / NUM_RAYS;
		ray++;
	}
}

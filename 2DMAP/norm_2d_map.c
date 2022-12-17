/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:00:11 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 11:02:22 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calculate_distance(t_cubd *cub, double x, double y)
{
	return (sqrt(pow(cub->x_p - x, 2) + pow(cub->y_p - y, 2)));
}

int	map_has_wall(t_cubd *cub, double x, double y)
{
	int	x_check;
	int	y_check;

	if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
		return (0);
	x_check = (int)floor(x / TILE_SIZE);
	y_check = (int)floor(y / TILE_SIZE);
	if (cub->map[y_check][x_check] != '1')
		return (1);
	return (0);
}

int	manag(int keycode, t_cubd *cub)
{
	double	posx;
	double	posy;

	posx = 0.0;
	posy = 0.0;
	if (keycode == 53 || keycode == 12)
		exit(1);
	else if (keycode == KEY_D)
		norm_key_d(cub, posx, posy);
	else if (keycode == KEY_A)
		norm_key_a(cub, posx, posy);
	else if ((keycode == KEY_DOWN || keycode == KEY_S))
		norm_key_down(cub, posx, posy);
	else if ((keycode == KEY_UP || keycode == KEY_W))
		norm_key_up(cub, posx, posy);
	else if (keycode == KEY_LEFT)
		cub->ang -= 0.25;
	else if (keycode == KEY_RIGHT)
		cub->ang += 0.25;
	return (1);
}

void	pixelput(t_cubd *cub, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WITH && y >= 0 && y < WIN_HIGHT)
		cub->add[x + y * WIN_WITH] = color;
}

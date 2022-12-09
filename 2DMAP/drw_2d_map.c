/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drw_2d_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 02:08:04 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/09 19:57:12 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixelput(t_cubd *cub, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WITH && y >= 0 && y < WIN_HIGHT)
		cub->add[x + y * WIN_WITH] = color;
}

unsigned int	pixelget(t_cubd *cub, int x, int y, int i)
{
	char	*color;

	color = cub->texture[i].add + y * cub->texture[i].len + x
		* (cub->texture[i].bp / 8);
	return (*(int *)color);
}

int	manag(int keycode, t_cubd *cub)
{
	double	posx;
	double	posy;

	if (keycode == 53 || keycode == 12)
	{
		write(1, "exit\n", 5);
		exit(1);
	}
	else if (keycode == KEY_D)
	{
		posx = cub->x_player - 17 * cos(cub->ang + 1.5708);
		posy = cub->y_player - 17 * sin(cub->ang + 1.5708);
		if (map_has_wall(cub, posx, posy))
		{
			cub->x_player = cub->x_player - 11 * cos(cub->ang + 1.5708);
			cub->y_player = cub->y_player - 11 * sin(cub->ang + 1.5708);
		}
	}
	else if (keycode == KEY_A)
	{
		posx = cub->x_player + 17 * cos(cub->ang + 1.5708);
		posy = cub->y_player + 17 * sin(cub->ang + 1.5708);
		if (map_has_wall(cub, posx, posy)
			&& map_has_wall(cub, cub->x_player, posy)
			&& map_has_wall(cub, posx, cub->y_player))
		{
			cub->x_player = cub->x_player + 11 * cos(cub->ang + 1.5708);
			cub->y_player = cub->y_player + 11 * sin(cub->ang + 1.5708);
		}
	}
	else if ((keycode == KEY_DOWN || keycode == KEY_S))
	{
		posx = cub->x_player + 17 * cos(cub->ang);
		posy = cub->y_player + 17 * sin(cub->ang);
		if (map_has_wall(cub, posx, posy)
			&& map_has_wall(cub, cub->x_player, posy)
			&& map_has_wall(cub, posx, cub->y_player))
		{
			cub->x_player = cub->x_player + 11 * cos(cub->ang);
			cub->y_player = cub->y_player + 11 * sin(cub->ang);
		}
	}
	else if ((keycode == KEY_UP || keycode == KEY_W))
	{
		posx = cub->x_player - 17 * cos(cub->ang);
		posy = cub->y_player - 17 * sin(cub->ang);
		if (map_has_wall(cub, posx, posy)
			&& map_has_wall(cub, cub->x_player, posy)
			&& map_has_wall(cub, posx, cub->y_player))
		{
			cub->x_player = cub->x_player - 11 * cos(cub->ang);
			cub->y_player = cub->y_player - 11 * sin(cub->ang);
		}
	}
	else if (keycode == KEY_LEFT)
		cub->ang -= 0.25;
	else if (keycode == KEY_RIGHT)
		cub->ang += 0.25;
	return (1);
}

int	new_map(t_cubd *cub)
{
	mlx_destroy_image(cub->mlx, cub->img);
	cub->img = mlx_new_image(cub->mlx, WIN_WITH,WIN_HIGHT);
	cub->add = (int*)mlx_get_data_addr(cub->img, &cub->b, &cub->l, &cub->e);
	draw(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
	return (0);
}

char	mapHasWallAt(t_cubd *cub, float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;

	// if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
	// 	return ('1');
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	return (cub->map[mapGridIndexY][mapGridIndexX]);
}

int	map_has_wall(t_cubd *cub, double x, double y)
{
	int	x_check;
	int	y_check;

	// if (x < 0 || x > cub->todmap->with || y < 0 || y > cub->todmap->hight)
	// 	return (0);
	x_check = (int)floor(x / TILE_SIZE);
	y_check = (int)floor(y / TILE_SIZE);
	if (cub->map[y_check][x_check] != '1')
		return (1);
	return (0);
}

double	calculate_distance(t_cubd *cub, double x, double y)
{
	return (sqrt(pow(cub->x_player - x, 2) + pow(cub->y_player - y, 2)));
}

void	norm_ray_distance(t_cubd *cub, double x_check, double y_check, int ray)
{
	cub->rays[ray]->wallhitx = x_check;
	cub->rays[ray]->wallhity = y_check;
	cub->rays[ray]->projectiowalls = (TILE_SIZE / cub->rays[ray]->distance) * cub->rays[ray]->projectionplan;
	cub->rays[ray]->wallsheight = (int)cub->rays[ray]->projectiowalls;
	cub->rays[ray]->walltoppixel = (WIN_HIGHT / 2) - (cub->rays[ray]->wallsheight / 2);
    if (cub->rays[ray]->walltoppixel < 0)
        cub->rays[ray]->walltoppixel = 0;
    else
        cub->rays[ray]->walltoppixel = cub->rays[ray]->walltoppixel;
    cub->rays[ray]->wallbottompixel = (WIN_HIGHT / 2) + (cub->rays[ray]->wallsheight / 2);
    if(cub->rays[ray]->wallbottompixel > WIN_HIGHT)
        cub->rays[ray]->wallbottompixel = WIN_HIGHT;
    else
        cub->rays[ray]->wallbottompixel = cub->rays[ray]->wallbottompixel;
}

void	ray_distance(t_cubd *cub, double rayangle, int ray)
{
    double i = 0;
    double x_check;
    double y_check;
    double distancedis;

    cub->rays[ray]->projectionplan = (WIN_WITH / 2 ) / tan(FOV_ANGLE / 2) - 150;
    while(i >= 0 && (i < WIN_WITH || i < WIN_HIGHT))
    {
        x_check = cub->x_player - cos(rayangle) * i;
        y_check = cub->y_player - sin(rayangle) * i;
        if (!map_has_wall(cub,  x_check , y_check ) ||  !map_has_wall(cub, x_check, cub->y_player - sin(rayangle) * (i - 1))
			|| !map_has_wall(cub, cub->x_player  - cos(rayangle) * (i - 1), y_check))
        {
			cub->rays[ray]->rayangle = rayangle;
			distancedis = calculate_distance(cub,(cub->x_player - cos(rayangle) * i) ,(cub->y_player - sin(rayangle) * i));
			cub->rays[ray]->distance = distancedis * cos(cub->rays[ray]->rayangle - cub->ang);
			norm_ray_distance(cub, x_check, y_check, ray);
			break ;
        }
        i += 1;
    }
}

void	draw_rays(t_cubd *cub)
{
	double	rayangle;
	int		ray;
	int		i;
	
	i = 0;
	rayangle = cub->ang - 0.5235;
	ray = 0;
	while (rayangle < cub->ang + 0.5235)
	{
		ray_distance(cub, rayangle, ray);
		rayangle += FOV_ANGLE / NUM_RAYS;
		ray++;
	}
}
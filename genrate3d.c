/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genrate3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:43:21 by schoukou          #+#    #+#             */
/*   Updated: 2022/12/09 20:07:30 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	direction(t_cubd *cub, int ray)
{
	if (cub->map[((int)(cub->rays[ray]->wallhity + 1))
		/ TILE_SIZE][(int)cub->rays[ray]->wallhitx / TILE_SIZE] == '0')
		return (1);
	if (cub->map[(int)cub->rays[ray]->wallhity
			/ TILE_SIZE][((int)(cub->rays[ray]->wallhitx + 1))
				/ TILE_SIZE] == '0')
		return (2);
	if (cub->map[((int)(cub->rays[ray]->wallhity - 1))
		/ TILE_SIZE][(int)cub->rays[ray]->wallhitx / TILE_SIZE] == '0')
		return (3);
	if (cub->map[(int)cub->rays[ray]->wallhity
			/ TILE_SIZE][((int)(cub->rays[ray]->wallhitx - 1))
				/ TILE_SIZE] == '0')
		return (4);
	return (0);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

void	norm_generate3d(t_cubd *cub, int ray, double i)
{
	if (direction(cub, ray) == 1)
		pixelput(cub, ray, i, pixelget(cub, cub->norm.textureoffset_x,
				cub->norm.textureoffset_y, 0));
	if (direction(cub, ray) == 3)
		pixelput(cub, ray, i, pixelget(cub, cub->norm.textureoffset_x,
				cub->norm.textureoffset_y, 1));
	if (direction(cub, ray) == 2)
		pixelput(cub, ray, i, pixelget(cub, cub->norm.textureoffset_x,
				cub->norm.textureoffset_y, 2));
	if (direction(cub, ray) == 4)
		pixelput(cub, ray, i, pixelget(cub, cub->norm.textureoffset_x,
				cub->norm.textureoffset_y, 3));
}

void	generate3d(t_cubd *cub)
{
	double	i;
	int		ray;
	int		j;

	ray = 0;
	i = 0;
	while (ray < NUM_RAYS)
	{
		j = 0;
		j = generate3d_sky(cub, j, ray);
		i = j;
		cub->norm.textureoffset_x = return_offsetx(cub, ray);
		while (i < cub->rays[ray]->wallbottompixel)
		{
			cub->norm.distancefromtop = i + (cub->rays[ray]->wallsheight / 2)
				- (WIN_HIGHT / 2);
			cub->norm.textureoffset_y = cub->norm.distancefromtop
				* ((float)TILE_SIZE / cub->rays[ray]->wallsheight);
			norm_generate3d(cub, ray, i);
			i++;
		}
		j = cub->rays[ray]->wallbottompixel;
		generate3d_floor(cub, j, ray);
		ray++;
	}
}

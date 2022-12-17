/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate3d_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 19:53:42 by schoukou          #+#    #+#             */
/*   Updated: 2022/12/10 10:56:12 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	generate3d_sky(t_cubd *cub, int j, int ray)
{
	while (j < cub->rays[ray]->walltoppixel)
	{
		pixelput(cub, ray, j, rgb_to_int(cub->c_col[0],
				cub->c_col[1], cub->c_col[2]));
		j++;
	}
	return (j);
}

void	generate3d_floor(t_cubd *cub, int j, int ray)
{
	while (j < WIN_HIGHT)
	{
		pixelput(cub, ray, j, rgb_to_int(cub->f_col[0],
				cub->f_col[1], cub->f_col[2]));
		j++;
	}
}

int	return_offsetx(t_cubd *cub, int ray)
{
	if (direction(cub, ray) == 2 || direction(cub, ray) == 4)
		cub->norm.txoffset_x = (int)cub->rays[ray]->wallhity % TILE_SIZE;
	else
		cub->norm.txoffset_x = (int)cub->rays[ray]->wallhitx % TILE_SIZE;
	return (cub->norm.txoffset_x);
}

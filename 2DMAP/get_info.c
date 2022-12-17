/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kouc <ael-kouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:43:28 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/12/10 10:26:07 by ael-kouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	norm_key_d(t_cubd *cub, double posx, double posy)
{
	posx = cub->x_p - 20 * cos(cub->ang + 1.5708);
	posy = cub->y_p - 20 * sin(cub->ang + 1.5708);
	if (map_has_wall(cub, posx, posy))
	{
		cub->x_p = cub->x_p - 11 * cos(cub->ang + 1.5708);
		cub->y_p = cub->y_p - 11 * sin(cub->ang + 1.5708);
	}
}

void	norm_key_a(t_cubd *cub, double posx, double posy)
{
	posx = cub->x_p + 20 * cos(cub->ang + 1.5708);
	posy = cub->y_p + 20 * sin(cub->ang + 1.5708);
	if (map_has_wall(cub, posx, posy)
		&& map_has_wall(cub, cub->x_p, posy)
		&& map_has_wall(cub, posx, cub->y_p))
	{
		cub->x_p = cub->x_p + 11 * cos(cub->ang + 1.5708);
		cub->y_p = cub->y_p + 11 * sin(cub->ang + 1.5708);
	}
}

void	norm_key_down(t_cubd *cub, double posx, double posy)
{
	posx = cub->x_p + 20 * cos(cub->ang);
	posy = cub->y_p + 20 * sin(cub->ang);
	if (map_has_wall(cub, posx, posy)
		&& map_has_wall(cub, cub->x_p, posy)
		&& map_has_wall(cub, posx, cub->y_p))
	{
		cub->x_p = cub->x_p + 11 * cos(cub->ang);
		cub->y_p = cub->y_p + 11 * sin(cub->ang);
	}
}

void	norm_key_up(t_cubd *cub, double posx, double posy)
{
	posx = cub->x_p - 20 * cos(cub->ang);
	posy = cub->y_p - 20 * sin(cub->ang);
	if (map_has_wall(cub, posx, posy)
		&& map_has_wall(cub, cub->x_p, posy)
		&& map_has_wall(cub, posx, cub->y_p))
	{
		cub->x_p = cub->x_p - 11 * cos(cub->ang);
		cub->y_p = cub->y_p - 11 * sin(cub->ang);
	}
}

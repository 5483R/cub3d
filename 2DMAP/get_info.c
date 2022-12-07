/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoukou <schoukou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 01:43:28 by ael-kouc          #+#    #+#             */
/*   Updated: 2022/11/21 01:55:12 by schoukou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int calc_with(char **map)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(map[i])
	{
		if(j < (int)ft_strlen(map[i]))
			j = (int)ft_strlen(map[i]);
		i++;
	}
	return(j);
}

int	calc_hight(char **map)
{
	return(lent_double_p(map));
}

t_tood	*get_info_of2d(cub3d_t *cub)
{
	t_tood *todmap;

	todmap = malloc(sizeof(t_tood));
	todmap->hight = calc_hight(cub->map) * TILE_SIZE;
	todmap->with = calc_with(cub->map) * TILE_SIZE;
	return(todmap);
}

int	face_up_down(double angle)
{
	if(angle > 0 && angle < M_PI)
		return(FACE_DOWN);
	else
		return(FACE_UP);
}

int	face_right_left(double angle)
{
	if(angle < 0.5 * M_PI || angle > 1.5 * M_PI)
		return(FACE_RIGHT);
	else
		return(FACE_LEFT);
}